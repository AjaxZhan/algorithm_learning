/*
title: 字符变换
Tag: BFS 优化 双向BFS
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;
const int N = 6;
int n;
string src,dst;
// 字符串变换规则
string ra[N],rb[N];


// 搜索的扩展过程
int extend(queue<string>&q,unordered_map<string,int>&da,unordered_map<string,int>&db,string ra[], string rb[])
{
    // 拓展一层：和队首相同的元素
    int h = da[q.front()];
    while(q.size() && da[q.front()] == h){
        auto t = q.front();
        q.pop();
        // 枚举规则 + 子串
        for(int i=0;i<n;i++){
            for(int j=0;j<t.size();j++){
                if(t.substr(j,ra[i].size()) == ra[i]){
                    string nextState = t.substr(0,j) + rb[i] + t.substr(j+ra[i].size());
                    if(db.count(nextState)) return da[t] + db[nextState] + 1;
                    if(da.count(nextState)) continue;
                    da[nextState] = da[t] + 1;
                    q.push(nextState);
                }
            }
        }
    }
    return 11;
}
// 双向BFS
int bfs(){

    if(src == dst) return 0;
    // 队列
    queue<string>qa,qb;
    // 距离
    unordered_map<string,int>da,db;
    qa.push(src);
    qb.push(dst);
    da[src] = db[dst] = 0;

    int step = 0;

    // 两个队列必须都不为空，才能连通
    while(qa.size() && qb.size()){
        int num = 0;    
        if(qa.size() < qb.size()){
            num = extend(qa,da,db,ra,rb);
        }else{
            num = extend(qb,db,da,rb,ra);
        }

        if(num <=10) return num;
        if(++step == 10) return -1;
    }

    return -1;
}

int main(){
    cin >> src >> dst;
    while(cin >> ra[n] >> rb[n]) n++;
    int res = bfs();
    if(res == -1) cout << "NO ANSWER!";
    else cout << res;
    return 0;
}