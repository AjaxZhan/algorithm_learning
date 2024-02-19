/*
title: 迷宫问题
Tag: BFS 最短路
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define x first
#define y second
using namespace std;
typedef pair<int,int>PII;
const int N = 1010;
int n;
int g[N][N];
PII q[N*N];
PII past[N][N]; // 存储上一个状态
int dx[4] = {-1,0,1,0},dy[4] = {0,1,0,-1};
void bfs(int xx, int yy){ 
    int hh = 0,tt = 0;
    q[0] = {xx,yy};
    memset(past,-1,sizeof past);
    past[xx][yy] = {0,0};

    while(hh <= tt){
        PII t = q[hh++];
        for(int i=0;i<4;i++){
            int nx = t.x + dx[i], ny = t.y+dy[i];
            if(nx <0 || nx>=n || ny <0 || ny>=n) continue;
            if(g[nx][ny] == 1) continue;
            if(past[nx][ny].x != -1) continue;
            q[++tt] = {nx,ny};
            past[nx][ny] = t;
        }
    }
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&g[i][j]);

    bfs(n-1,n-1);

    PII it = {0,0};
    while(true){
        printf("%d %d\n",it.x,it.y);
        if(it.x == n-1 && it.y == n-1) break;
        it = past[it.x][it.y];
    }

    return 0;
}