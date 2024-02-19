/*
title: 矩阵距离
Tag: BFS 多源BFS 虚拟原点
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define x first
#define y second
using namespace std;
typedef pair<int,int> PII;
const int N = 1010;
int n,m;
PII q[N*N];
char g[N][N];
int dist[N][N];
int dx[4] = {-1,0,1,0},dy[4] = {0,1,0,-1};

void bfs(){
    memset(dist,-1,sizeof dist);
    int hh=0, tt=-1; //虚拟点最开始没有加入进去
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(g[i][j] == '1'){
                q[++tt] = {i,j};
                dist[i][j] = 0;
            }

    while(hh <=tt){
        PII t = q[hh++];
        for(int i=0;i<4;i++){
            int a = t.x+dx[i], b = t.y+dy[i];
            if(a <0 || a>=n || b <0 || b>=m) continue;
            if(dist[a][b] != -1) continue;
            dist[a][b] = dist[t.x][t.y]+1;
            q[++tt] = {a,b};
        }
    }
}


int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",g[i]);
    bfs();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            printf("%d ",dist[i][j]);
        printf("\n");
    }

    return 0;
}