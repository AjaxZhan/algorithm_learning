/*
title: 八数码
from:
Tag: BFS A*算法
Code:
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
string ed = "12345678x";
int dx[4] = {-1,0,1,0},dy[4] = {0,1,0,-1};
char op[] = "urdl";
int f(string state){
    int res = 0;
    for(int i=0;i<state.size();i++){
        if(state[i]!='x'){
            int t =state[i] - '1';
            res+=abs(i/3 - t/3) + abs(i%3 - t%3);
        }
    }
    return res;
}
typedef pair<int,string>PIS; //估计距离 和 状态
string bfs(string start){
    //距离
    unordered_map<string, int> dist;
    unordered_map<string,pair<char,string>>prev; //记录前驱状态
    //优先队列，存放到终点的曼哈顿距离
    priority_queue<PIS,vector<PIS>,greater<PIS>>heap;

    dist[start] = 0;
    heap.push({f(start),start});
    
    while(heap.size()){
        auto t = heap.top();
        heap.pop();

        string state = t.y;
        if(state == ed) break;
        //找到x的位置
        int xx,yy;
        for(int i=0;i<9;i++)
            if(state[i] == 'x'){
                xx = i/3;
                yy = i%3;
                break;
            }
        string source = state;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                int a = xx+ dx[i];
                int b = yy + dy[i];
                if(a < 0 || a>=3 || b<0 || b>=3) continue;
                state = source;
                swap(state[xx*3+yy],state[a*3+b]);
                if(!dist.count(state) || dist[state] > dist[source] + 1){
                    dist[state] = dist[source] + 1;
                    prev[state] = {op[i],source};
                    heap.push({dist[state] + f(state),state});
                }

            }
        }

    }
    string res;
    while(ed!=start){
        res+=prev[ed].x;
        ed = prev[ed].y;
    }
    reverse(res.begin(),res.end());
    return res;

}
int main(){
    string start, seq;
    //seq为了算逆序对
    char c;
    while(cin >> c){
        start+=c;
        if(c!='x') seq+=c;
    }
    //求逆序对
    int cnt = 0;
    for(int i=0;i<8;i++)
        for(int j=i;j<8;j++){
            if(seq[i] > seq[j]) cnt++;
        }
    //逆序对数量是奇数则无解
    if(cnt&1) puts("unsolvable");
    else cout << bfs(start) << endl;
    return 0;
}