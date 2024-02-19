/*
title: 红与黑
Tag: DFS FloodFill
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 25;
int n,m;
char g[N][N];
bool st[N][N];
int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
int dfs(int x, int y){
    int cnt = 1;
    st[x][y]  = true;
    
    for(int i=0;i<4;i++){
        int a = x + dx[i], b = y + dy[i];
        if(a < 0 || a >=n || b <0 || b>=m) continue;
        if(g[a][b] != '.') continue;
        if(st[a][b]) continue;
        cnt+= dfs(a,b);
    }
    return cnt;
}

int main(){
    while(cin >> m >> n , m||n ){
        for(int i=0;i<n;i++) cin >> g[i];
        int sx,sy;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(g[i][j] == '@')
                {
                    sx = i;
                    sy = j;
                }
        memset(st,0,sizeof st);
        cout << dfs(sx,sy) << endl;   
    }


    return 0;
}