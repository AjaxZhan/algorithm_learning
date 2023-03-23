/*
title: 马走日
from: acwing 1116
Tag: DFS
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 10;
int T;
int n,m;
int x,y;
int ans;
int dx[8] = {-1,-2,-2,-1,1,2,2,1};
int dy[8] = {-2,-1,1,2,2,1,-1,-2};
bool st[N][N];
void dfs(int x , int y , int cnt){
    if(cnt == n*m){
        ans++;
        return;
    }
    for(int i=0;i<8;i++){
        int a = x+dx[i] ,b = y+dy[i];
        if(a <0 || a>=n || b < 0 || b>=m) continue;
        if(st[a][b]) continue;
        
        st[a][b] = true;
        dfs(a,b,cnt+1);
        st[a][b] = false;
    }
}
int main(){
    cin >> T;
    while(T--){
        cin >> n >> m >> x >> y;
        ans = 0;
        st[x][y] = true;
        dfs(x,y,1);
        st[x][y] = false;
        printf("%d\n",ans);
    }
    return 0;
}