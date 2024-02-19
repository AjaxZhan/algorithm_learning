/*
title: 武士风度的牛
Tag: BFS
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define x first
#define y second
using namespace std;
typedef pair<int,int>PII;
const int N = 155;
int n,m;
char g[N][N];
PII q[N*N];
int dx[8] = {-1,-2,-2,-1,1,2,2,1};
int dy[8] = {-2,-1,1,2,2,1,-1,-2};
int dist[N][N];
int bfs(){
    int sx = -1,sy = -1;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(g[i][j] == 'K'){
                sx = i;
                sy = j;
                break;
            }
    int hh = 0,tt = 0;
    q[0] = {sx,sy};
    memset(dist,-1,sizeof dist);
    dist[sx][sy] = 0;
    while(hh<=tt){
        PII t= q[hh++];
        for(int i=0;i<8;i++){
            int a = t.x+dx[i];
            int b = t.y+dy[i];
            if(a < 0 || a >=n || b<0 || b>=m) continue;
            if(g[a][b] == '*') continue;
            if(dist[a][b] != -1) continue;
            if(g[a][b] == 'H') return dist[t.x][t.y]+1;
            q[++tt] = {a,b};
            dist[a][b] = dist[t.x][t.y]+1;
        }
    }
}
int main(){
    scanf("%d%d",&m,&n);
    for(int i=0;i<n;i++) scanf("%s",g[i]);
    printf("%d",bfs());
    return 0;
}