/*
title: 迷宫
from: acwing 1112
Tag: dfs
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 110;
int n;
char g[N][N];
bool st[N][N];
int xa,ya,xb,yb;
int dx[4] = {-1,0,1,0},dy[4] = {0,1,0,-1};
bool dfs(int x, int y){
    if(g[x][y] == '#') return false;
    if(x == xb && y == yb) return true;
    st[x][y] = true;
    //枚举下一个分支
    for(int i=0;i<4;i++){
        int aa = x+dx[i];
        int bb = y+dy[i];
        if(aa < 0 || aa>=n || bb < 0 || bb>=n) continue;
        if(st[aa][bb]) continue;
        if(g[aa][bb] == '#') continue;
        if(dfs(aa,bb)) return true;
    }
    return false;
    
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%s",g[i]);
        memset(st,0,sizeof st);
        scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
        if(dfs(xa,ya)) puts("YES");
        else puts("NO");
    }

    return 0;
}