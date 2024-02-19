/*
title: 城堡计数
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
// FloodFill一般用pair<int,int>表示坐标
const int N = 55,M=N*N;
int g[N][N]; // 地图
PII q[M]; // 队列
bool st[N][N]; // 判重数组
int n,m;
// 方向和题目保持一致，都是用西北东南
int dx[4] = {0,-1,0,1},dy[4]={-1,0,1,0};

int bfs(int sx, int sy){
    int hh=0,tt=0;
    int area=0;
    q[0] = {sx,sy};
    st[sx][sy] = true;
    while(hh <= tt){
        PII t =  q[hh++];
        area++;
        for(int i=0;i<4;i++){
            int nx=t.x+dx[i],ny=t.y+dy[i];
            // 出界
            if(nx< 0 || nx >=n || ny <0 || ny >=m) continue;
            if(st[nx][ny]) continue;
            // 判断墙体
            if(g[t.x][t.y] >> i & 1) continue;
            q[++tt] = {nx,ny};
            st[nx][ny] = true;
        }
    }
    return area;
}

int main(){
    // 本题输入：用1248分别表示某个空格有没有西北东南墙。
    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> g[i][j];
    int cnt = 0, area = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(!st[i][j]){
                cnt++;
                area = max(area,bfs(i,j));
            }
    cout << cnt << endl;
    cout << area << endl;
    return 0;
}