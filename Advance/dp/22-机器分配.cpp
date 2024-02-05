/*
title: 机器分配
Tag: 分组背包 求方案
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 11,M = 16;
int n,m;
int f[N][M];
int w[N][M];
int g[N]; // 记录走的路径
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin >> w[i][j];
    
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            f[i][j] = f[i-1][j];
            for(int k=0;k<=j;k++)
                f[i][j] = max(f[i][j],f[i-1][j-k]+w[i][k]);
        }
    }
    cout << f[n][m] << endl;
    
    int j = m;
    for(int i=n;i>=1;i--)
        for(int k=0;k<=j;k++)
            if(j>=k && f[i][j] == f[i-1][j-k]+w[i][k]){
                g[i] = k;
                j -=k;
                break;
            }
    
    for(int i=1;i<=n;i++) cout  << i << ' ' << g[i] << endl;
    
    return 0;
}