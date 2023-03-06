/*
title: SPFA复习
from: acwing 851.
Tag: 
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
//SPFA类似于dijkstra堆优化版
const int N = 100010;
const int INF=  0x3f3f3f3f;
int n,m;
int h[N],e[N],ne[N],idx,w[N];
int dist[N];
bool st[N]; // 是否入队
void add(int a, int b, int c){
    w[idx] = c;
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int SPFA(){
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    queue<int>q;
    q.push(1);
    st[1] = true;
    while(q.size()){
        int t = q.front();
        q.pop();
        st[t] = false;
        for(int i= h[t];i!=-1;i= ne[i]){
            int j = e[i];
            if(dist[j] > dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                if(!st[j]){
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return dist[n];
}

int main(){
    //邻接表不要忘记初始化
    memset(h,-1,sizeof h);
    scanf("%d%d",&n,&m);
    while(m--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
    }
    int res = SPFA();
    if(res == INF) puts("impossible");
    else printf("%d\n",res);
    return 0;
}