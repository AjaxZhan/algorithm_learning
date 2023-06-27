/*
title: 城堡问题
Tag: FloodFill BFS
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

#define x first
#define y second
using namespace std;
typedef pair<int,int>PII;
const int N = 55, M = N*N;

PII q[M];
bool st[N][N];
int g[N][N];
int n,m;

/**
 * @brief Flood Fill
 * 
 * @param 起始坐标
 * @return 连通块面积
 */
int bfs(int sx, int sy){
    //方向，左上右下，符合题目二进制位
    int dx[4] = {0,-1,0,1}, dy[4] = {-1,0,1,0};
    int hh =0, tt = 0;
    int area = 0;
    q[0] = {sx,sy};
    st[sx][sy] = true;
    
    while(hh<=tt){
        auto t = q[hh++];
        area++;//出队的时候统计个数，入队也行

        //四个方向，用偏移量
        for(int i=0;i<4;i++)
        {
            int a = t.x + dx[i];
            int b = t.y + dy[i];
            if(a < 0 || a>=n || b <0 || b>=m) continue; //出界
            if(st[a][b]) continue; // 是否遍历过
            if(g[t.x][t.y] >> i & 1) continue; // ！利用二进制判断能否连通
            
            //可以走到
            q[++tt] = {a,b};
            st[a][b] = true;
        }
    }
    return area;
}

int main(){
    
    cin >> n >> m; // 数比较少用cin
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> g[i][j];
    
    int cnt = 0, area = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(!st[i][j])
            {
                //bfs返回面积
                area = max(area,bfs(i,j));
                cnt++;
            }

    cout << cnt << endl;
    cout << area << endl;

    return 0;
}