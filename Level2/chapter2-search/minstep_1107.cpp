/*
title: 魔板
from: acwing 1107
Tag: BFS 最小步数模型
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;
//状态用哈希表存
unordered_map<string,int>dist; // 距离
unordered_map<string,pair<char,string>>pre; // 上一个状态，存储方案操作代码 以及 上一个状态
queue<string>q; //队列
string res, eend,start; // 方案代码、最终状态、起始状态
char tmp[10];//临时字符数组，处理读取的最终状态

//打表获取三种状态
string get(string t , int op){
    string ans;
    if(op == 0) ans = {t[4],t[5],t[6],t[7],t[0],t[1],t[2],t[3]};
    if(op == 1) ans = {t[3],t[0],t[1],t[2],t[7],t[4],t[5],t[6]};
    if(op == 2) ans = {t[0],t[5],t[1],t[3],t[4],t[6],t[2],t[7]};
    return ans;
}
//返回方案数
int bfs(){
    dist[start] = 0;
    q.push(start);
    while(q.size()){
        auto t = q.front();
        q.pop();
    
        if(t == eend) return dist[t];
        for(int i=0;i<3;i++){
            string k = get(t,i);
            //如果没有走过
            if(!dist.count(k)){
                dist[k] = dist[t] + 1;
                pre[k] = {'A'+i,t}; // A+i表示方案数
                q.push(k);
            }
        }
    }
}
int main(){
    start = "12348765";
    //  起始状态处理，映射到自己先规定的顺序
    for(int i=0;i<8;i++){
        cin >> tmp[i];
    }
    reverse(tmp+4,tmp+8);
    for(int i=0;i<8;i++ )eend.push_back(tmp[i]);

    
    cout << bfs() << endl;

    //输出方案数，从后往前推，最后reverse一下
    while(eend!=start){
        res.push_back(pre[eend].first);
        eend = pre[eend].second;
    }
    reverse(res.begin(),res.end());

    cout << res ;

    return 0;
}