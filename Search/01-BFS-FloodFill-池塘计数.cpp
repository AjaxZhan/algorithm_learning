/*
title: 池塘计数
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
const int N = 1010,M=N*N;
char g[N][N]; // 地图
PII q[M]; // 队列
bool st[N][N]; // 判重数组
int n,m;

void bfs(int sx, int sy){
    // 数组模拟队列
    int hh=0,tt=0;
    q[0] = {sx,sy};
    st[sx][sy] = true;

    while(hh <=tt){
        PII t = q[hh++];
        // 八连通
        for(int i=t.x-1;i<=t.x+1;i++)
            for(int j=t.y-1;j<=t.y+1;j++){
                // 中间挖掉
                if(i==t.x && j==t.y) continue;
                // 判断是否出界
                if(i<0 || i>=n || j<0 || j>=m) continue;
                if(g[i][j] == 'W' && !st[i][j]){
                    q[++tt] = {i,j};
                    st[i][j] = true;
                }
            }
    }

}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%s",&g[i]); // 一次读一行
    }
    // BFS
    int res = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j] == 'W' && !st[i][j]){
                bfs(i,j);
                res++;
            }
        }
    }
    printf("%d\n",res);
    return 0;
}