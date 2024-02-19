/*
title: 魔板
Tag: BFS 最小步数
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;
// 思路好想，代码不好写
string str, dst;
char buf[10];
queue<string>q;
// 距离
unordered_map<string,int>dist;
// 上一个状态
unordered_map<string,pair<char,string>>past;

// 进行三种操作
string op(string src, int op){
    string res;
    switch (op)
    {
        case 0:
            res = {src[4],src[5],src[6],src[7],src[0],src[1],src[2],src[3]};
            break;
        case 1:
            res = {src[3],src[0],src[1],src[2],src[7],src[4],src[5],src[6]};
            break;
        case 2:
            res = {src[0],src[5],src[1],src[3],src[4],src[6],src[2],src[7]};
            break;
    }
    return res;
}

// 返回方案数
int bfs(){
    dist[str] = 0;
    q.push(str);
    while(q.size()){
        auto t = q.front();
        q.pop();

        if(t == dst) return dist[t];
        for(int i=0;i<3;i++){
            string nxt = op(t,i);
            if(!dist.count(nxt)){
                dist[nxt] = dist[t] + 1;
                past[nxt] = {'A'+i,t};
                q.push(nxt);
            }
        }
    }
}

int main(){
    str = "12348765";

    for(int i=0;i<8;i++ ){
        cin >> buf[i];
    }
    reverse(buf+4,buf+8);
    for(int i=0;i<8;i++ )dst.push_back(buf[i]);

    cout << bfs() << endl;

    string res;
    while(dst!=str){
        res.push_back(past[dst].first);
        dst = past[dst].second;
    }
    reverse(res.begin(),res.end());

    cout << res << endl;

    
    return 0;
}