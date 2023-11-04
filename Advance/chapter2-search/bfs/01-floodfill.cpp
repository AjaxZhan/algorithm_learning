/*
title: 池塘计数
Tag: FloodFill BFS 
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

#define x first
#define y second

using namespace std;
const int N = 1010 , M = N*N;
typedef pair<int,int>PII; //存放下标

int n,m; // 长宽
char g[N][N]; //地图
PII q[M]; //队列
bool st[N][N]; //BFS判重数组

/**
 * @brief Flood Fill
 * 
 * @param 起点和终点
 */
void bfs(int sx, int sy){
    int hh =0, tt = 0; //模拟队列
    //起点入队
    q[0] = {sx,sy};
    st[sx][sy] = true;
    //BFS
    while(hh <=tt){
        PII t = q[hh++];
        //八连通，一般两层for
        for(int i= t.x-1;i<=t.x+1;i++)
            for(int j=t.y-1;j<=t.y+1;j++)
            {
                if(i== t.x && j==t.y) continue; //挖掉中间
                if(i <0 || i>=n || j<0|| j>=m ) continue; //超出地图
                if(g[i][j] == '.' || st[i][j]) continue; // 不是水or遍历过
                
                //合法，入队
                q[++tt] = {i,j};
                st[i][j] = true;
            }
    }
}

int main(){
    
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%s",g[i]);

    int cnt = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(g[i][j] == 'W' && !st[i][j]){
                bfs(i,j);
                cnt++;
            }
    
    printf("%d\n",cnt);

    return 0;
}