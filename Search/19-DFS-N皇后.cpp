/*
title: N皇后
Tag: DFS
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 10;
int n;
char g[N][N];
// 列，对角线，反对角线
bool col[N], dg[2*N],udg[2*N];
void dfs(int u){
    if(u == n){
        for(int i=0;i<n;i++){
            cout << g[i]<< endl;
        }
        cout << endl;
        return;
    }
    // dg: y=x+b -> b = y-x -> b = y-x+n为了防止下标出现负数
    for(int i=0;i<n;i++){
        if(!col[i] && !dg[u+i] && !udg[i-u+n]){
            col[i] = dg[u+i] = udg[i-u+n] = true;
            g[u][i] = 'Q';
            dfs(u+1);
            col[i] = dg[u+i] = udg[i-u+n] = false;
            g[u][i] = '.';
        }
    }


}
int main(){
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            g[i][j] = '.';
    dfs(0);    
    return 0;
}