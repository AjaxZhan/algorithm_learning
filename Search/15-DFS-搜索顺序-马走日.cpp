/*
title: 马走日
Tag: DFS 搜索顺序
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 10;
int n,m,x,y;
int ans;
int dx[] = {-1,-2,-2,-1,1,2,2,1};
int dy[] = {-2,-1,1,2,2,1,-1,-2};
bool st[N][N];
void dfs(int x, int y,int cnt){
    if(cnt == n *m){
        ans += 1;
        return;
    }
    for(int i=0;i<8;i++){
        int a = x + dx[i], b = y + dy[i];
        if(a < 0 || a >= n || b < 0 || b >= m) continue;
        if(st[a][b]) continue;
        st[a][b] = true;
        dfs(a,b,cnt+1);
        st[a][b] = false;
    }

}
int main(){
    int T;
    cin >>T;
    while(T--){
        ans = 0;
        cin >> n >> m >> x >> y;
        
        st[x][y] = true;
        dfs(x,y,1); 
        st[x][y] = false;
        
        cout << ans << endl;
    }
    
    return 0;
}