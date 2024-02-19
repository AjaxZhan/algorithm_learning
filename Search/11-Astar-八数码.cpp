/*
title: 八数码
Tag: A*算法
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <unordered_map>
#define x first
#define y second
using namespace std;
typedef pair<int,string> PIS;
// 方向
int dx[] = {-1,0,1,0},dy[] = {0,-1,0,1};
char op[] = {'u','l','d','r'};
// 估计函数
int f(string state){
    int res = 0;
    for(int i=0;i<state.size();i++){
        if(state[i] == 'x') continue;
        int x = (state[i]-'1')/3,y = (state[i]-'1')%3;
        res += abs(x-i/3) + abs(y-i%3);
    }
    return res;
}   

// A*算法
string bfs(string start){
    string end = "12345678x";
    unordered_map<string,int>dist;
    unordered_map<string,pair<string,char>>prev;
    priority_queue<PIS,vector<PIS>,greater<PIS>>heap;

    heap.push({f(start),start});
    dist[start]=0;
    while(heap.size()){
        auto t = heap.top();
        heap.pop();
        string state = t.y;
        if(state == end) break;
        
        int xx,yy;
        for(int i=0;i<state.size();i++){
            if(state[i] == 'x'){
                xx = i/3;
                yy = i%3;
                break;
            }
        }
        string source = state;
        int step = dist[source];
        for(int i=0;i<4;i++){
            int a = xx+dx[i],b = yy+dy[i];
            if(a < 0 || a >= 3 || b < 0 || b >= 3) continue;
            
            swap(state[xx*3+yy],state[a*3+b]);
            if(!dist.count(state) || dist[state] > step + 1){
                dist[state] = step + 1;
                prev[state] = {source,op[i]};
                heap.push({dist[state] + f(state),state});
            }
            swap(state[xx*3+yy],state[a*3+b]);

        }

    }
    string res;
    while(end!=start){
        res+=prev[end].y;
        end = prev[end].x;
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    char c;
    string start,seq;
    for(int i=0;i<9;i++){
        cin >> c;
        start+=c;
        if(c != 'x') seq+=c;
    }
    // 求解逆序对数量
    int cnt = 0;
    for(int i=0;i<9;i++)
        for(int j=i+1;j<9;j++)
            if(seq[i] > seq[j]) cnt++;
    if(cnt % 2) cout << "unsolvable" << endl;
    else cout << bfs(start) << endl;

    return 0;
}