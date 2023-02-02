/*
01背包问题--没优化版本
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1010;

int n,m; //n所有物品个数，m为背包容量
int v[N],w[N];
int f[N][N];

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> v[i] >> w[i];
    
    for(int i=1;i<=n;i++)
        for(int j=0;j<=m;j++){

            f[i][j] = f[i-1][j]; // 不含第i件物品
            //包含第i件物品，需要看是否装得下
            if(j>=v[i]) f[i][j] = max(f[i][j],f[i-1][j-v[i]] + w[i]);
            
        }
    
    cout << f[n][m] << endl; //输出答案

    return 0;
}