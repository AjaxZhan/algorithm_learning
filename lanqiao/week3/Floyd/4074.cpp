/*
title: 铁路和公路
from: acwing 4074
Tag: Floyd、dijkstra、SPFA均可
Code:
经过分析，只需要求两遍最短路问题即可。

*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m;
const int N = 410;
const int INF = 0x3f3f3f3f;
int f[N][N],g[N][N]; // 做两边Floyd，存储铁路和公路
int floyd(int d[][N]){
    //优化
    if(d[1][n] == 1) return 1; //必然有公路或者铁路是1
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
    return d[1][n];
}
int main(){
    scanf("%d%d",&n,&m);
    memset(f,0x3f,sizeof f);
    memset(g,0x3f,sizeof g);
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        f[a][b] = f[b][a] = 1;
    }
    //完全图，其它边都是公路
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i != j && f[i][j]!=1) g[i][j] = 1; //顺白处理一下自环
    
    int res = max(floyd(f),floyd(g));
    if(res == INF) res = -1;
    printf("%d\n",res);
    return 0;
}