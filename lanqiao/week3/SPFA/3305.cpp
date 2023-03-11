/*
title: 作物杂交
from: acwing 3305
Tag: SPFA dijkstra
Code:   
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 2020, M = N*N;
int n,m; 
int h[N],e[M],w[N],target[M],ne[M],idx;
int dist[N];
queue<int>q;
bool st[N];
void add(int a, int b , int c){
    e[idx] = b;
    target[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}
void spfa(){
    while(q.size()){
        auto x = q.front();
        q.pop();
        st[x] = false;
        for(int i=h[x];i!=-1;i=ne[i]){
            int y = e[i] , z= target[i];
            if(dist[z] > max(dist[x],dist[y]) + max(w[x] ,w[y])){
                dist[z] = max(dist[x],dist[y]) + max(w[x],w[y]);
                if(!st[z]){
                    q.push(z);
                    st[z]  = true;
                }
            }
        }
    }
}
int main(){
    int k,t;
    scanf("%d%d%d%d",&n,&m,&k,&t);
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    memset(dist,0x3f,sizeof dist);
    while(m--){
        int x;
        scanf("%d",&x);
        dist[x] = 0;
        q.push(x);
        st[x] = true;
    }
    while(k--){
        int a, b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
        add(b,a,c);
    }
    spfa();
    printf("%d\n",dist[t]); 
    return 0;
}