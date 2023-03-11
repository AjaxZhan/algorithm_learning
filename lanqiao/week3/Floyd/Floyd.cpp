/*
title: Flord求最短路
from: acwing 854
Tag: Floyd 
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 210;
const int INF = 0x3f3f3f3f;
int d[N][N];
int n,m,q;
void floyd(){
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
}
int main(){
    scanf("%d%d%d",&n,&m,&q);
    memset(d,0x3f,sizeof d);
    while(m--){
        int a, b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a == b) continue;
        d[a][b] = min(d[a][b],c); //重边
    }
    floyd();
    while(q--){
        int a, b;
        scanf("%d%d",&a,&b);
        int t = d[a][b];
        if(t > INF/2) puts("impossible");
        else printf("%d\n",t);
    }
    return 0;
}