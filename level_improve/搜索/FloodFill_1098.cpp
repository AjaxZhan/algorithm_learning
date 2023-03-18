/*
title: 城堡问题
from: acwing 1098
Tag: BFS FloodFill
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define x first
#define y second
typedef pair<int,int>PII;
const int N = 55,M = N*N;
PII q[M];
int g[N][N]; //每一个点用一个二进制数表示
bool st[N][N];  
int n,m;
//西北东南
int dx[4] = {0,-1,0,1},dy[4]= {-1,0,1,0};
int bfs(int sx, int sy){
    int hh = 0 ,tt = 0;
    int area = 0;
    q[0] = {sx,sy};
    st[sx][sy] = true;
    while(hh <=tt){
        PII t = q[hh++];
        area++;
        //遍历四个方向
        for(int i=0;i<4;i++){
            int xx = t.x + dx[i];
            int yy = t.y + dy[i];
            if(xx <0 || xx>=n || yy <0 || yy >=m) continue;
            if(st[xx][yy]) continue;
            if(g[t.x][t.y] >> i &1) continue; //有墙
            
            q[++tt] = {xx,yy};
            st[xx][yy]  = true;
        }
    }
    return area;
}
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++)    
        for(int j=0;j<m;j++)
            cin >> g[i][j];
    int cnt = 0, maxArea = 0;
    //遍历每个点
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(!st[i][j]){
                maxArea = max(maxArea,bfs(i,j));
                cnt++;
            }
        }
    cout << cnt << endl << maxArea << endl;
    return 0;
}