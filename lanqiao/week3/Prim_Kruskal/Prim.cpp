/*
title: Prim模板
from:
Tag:
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 510;
const int INF = 0x3f3f3f3f;
int g[N][N];
int n,m;
int dist[N];
bool st[N];
int prim(){
    memset(dist,0x3f,sizeof dist);
    int res = 0;
    for(int i= 0;i<n;i++){
        int t = -1;
        //找到不在连通块并且距离最近的点
        for(int j=1;j<=n;j++)
            if(!st[j] && (t == -1 || dist[t] > dist[j])) t= j;
        
        //判断是否连通
        if(i && (dist[t] == INF)) return INF;   
        //如果连同，添加权值
        if(i) res+=dist[t];//如果说这里放在for的后面，那么自环就可能会改变dist的值。
        st[t] = true;
        //和dijkstra的区别，是更新到连通块的距离，不是更新到原点的距离
        for(int j=1;j<=n;j++) dist[j] = min(dist[j],g[t][j]);
    }
    return res;
}
int main(){
    scanf("%d%d",&n,&m);
    memset(g,0x3f,sizeof g);
    while(m--){
        int a, b,c;
        scanf("%d%d%d",&a,&b,&c);
        g[a][b] = g[b][a] = min(g[a][b],c);
    }
    int res = prim();
    if(res == INF) puts("impossible");
    else printf("%d\n",res);

    return 0;
}