/*
title: 武士风度的牛
from: acwing 188
Tag: BFS 最短路
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 155,M = N*N;
typedef pair<int,int>PII;
#define x first
#define y second
int n,m;
char g[N][N];
//用dist来存距离，顺便判断是否遍历过
int dist[N][N];
PII q[M];

int dx[8] = {-1,-2,-2,-1,1,2,2,1};
int dy[8] = {-2,-1,1,2,2,1,-1,-2};


int bfs(){
    //找到起点
    int sx=-1,sy=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            if(g[i][j] == 'K'){
                sx = i;
                sy = j;
                break;
            }
        if(sx!=-1) break;
    }

    int hh = 0 ,tt = 0;
    q[0] = {sx,sy};
    memset(dist,-1,sizeof dist);
    dist[sx][sy] = 0;
    
    while(hh <=tt){
        PII t = q[hh++];
        for(int i=0;i<8;i++){
            int a = t.x+dx[i];
            int b = t.y+dy[i];
            if(a <0 || a>=n || b< 0 || b>=m) continue;
            if(g[a][b] == '*') continue;
            if(dist[a][b]!=-1) continue;
            
            if(g[a][b] == 'H') return dist[t.x][t.y]+1;
            q[++tt] = {a,b};
            dist[a][b] = dist[t.x][t.y]+1;
        }
    }
}

int main(){
    cin >> m >> n; //先输入列数再输入行数
    for(int i=0;i<n;i++)
        scanf("%s",&g[i]);
    cout << bfs() << endl;

    return 0;
}