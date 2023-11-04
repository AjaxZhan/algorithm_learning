/*
title: 1097 池塘计数
from: acwing 1097
Tag: FloodFill BFS
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define x first
#define y second
const int N = 1010 , M = N * N;
typedef pair<int,int>PII; // 存坐标
PII q[M]; // 队列
bool st[N][N];
char g[N][N];
int n,m;
void bfs(int sx,int sy){
    int hh = 0, tt =0;
    q[0] = {sx,sy};
    st[sx][sy] = true;

    while(hh <=tt){
        PII t = q[hh++];

        //这里采用两层循环的方式来覆盖八连通
        for(int i=t.x-1;i<=t.x+1;i++){
            for(int j = t.y-1;j<=t.y+1;j++){
                if(i == t.x && j == t.y) continue;
                if(i < 0 || i>=n || j < 0 || j>=m) continue;
                if(g[i][j] == '.') continue;
                if(st[i][j]) continue;

                q[++tt] = {i,j};
                st[i][j] = true;
            }
        }
    }
}
int main(){
    cin >>n >> m;
    for(int i=0;i<n;i++) scanf("%s",g[i]);
    
    int res = 0;
    //对每个点做一下FloodFill
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(g[i][j] == 'W' && !st[i][j]){
                bfs(i,j);
                res++;
            }
        }
    cout << res << endl;
    return 0;
    
}