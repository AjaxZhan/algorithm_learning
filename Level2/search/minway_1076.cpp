/*
title: 迷宫问题
from: acwing 1076
Tag: BFS 最短路
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define x first
#define y second
using namespace std;
typedef pair<int,int>PII;
const int N = 1010, M= N*N;
int n;
int g[N][N];
PII q[M];
PII pre[N][N]; //用来标识每个点是否被搜索过，并且记录从哪一个点走过来
int dx[4] = {-1,0,1,0},dy[4] = {0,1,0,-1};
void bfs(int sx, int sy){
    int hh = 0,tt = 0;
    q[0] = {sx,sy};

    memset(pre,-1,sizeof pre);
    //标记走过了，第一个点从哪来无所谓
    pre[sx][sy] = {0,0};

    while(hh <= tt){
        PII t = q[hh++];
        for(int i=0;i<4;i++){
            int a = t.x + dx[i],b= t.y + dy[i];
            if(a < 0 || a>=n || b<0 || b>=n) continue;
            if(g[a][b] == 1) continue;
            if(pre[a][b].x!=-1) continue; //被遍历过

            q[++tt] = {a,b};
            pre[a][b] = t;
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&g[i][j]);
    //反向搜，最后直接从起点往回找。
    bfs(n-1,n-1);
    PII end(0,0);
    while(true){
        printf("%d %d\n",end.x,end.y);
        if(end.x == n-1 && end.y == n-1) break;
        end = pre[end.x][end.y];
    }

    return 0;
}