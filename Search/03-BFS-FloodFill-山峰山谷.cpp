/*
title: 山峰山谷
Tag: BFS
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define x first
#define y second
using namespace std;
const int N = 1010,M=N*N;
typedef pair<int,int>PII;
int g[N][N]; // 地图
PII q[M];
bool st[N][N];
int n;

void bfs(int xx, int yy , bool &higher, bool &lower){
    int hh=0,tt=0;
    q[0] = {xx,yy};
    st[xx][yy] = true;

    while(hh <= tt){
        PII t = q[hh++];
        for(int i=t.x-1;i<=t.x+1;i++)
            for(int j=t.y-1;j<=t.y+1;j++){
                if(i==t.x && j==t.y) continue;
                if(i <0 || i>=n || j<0 || j>=n) continue;
                if(g[i][j]!=g[t.x][t.y]){
                    if(g[i][j] > g[t.x][t.y]) higher = true;
                    else lower = true;
                }else if(!st[i][j]){
                    q[++tt] = {i,j};
                    st[i][j] = true;
                }
            }
    }
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&g[i][j]);
    
    int peak = 0, valley = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(!st[i][j]){
                bool higher = false, lower = false;
                bfs(i,j,higher,lower);
                if(!higher) peak++;
                if(!lower) valley++;
            }
    printf("%d %d\n",peak,valley);
    return 0;
}