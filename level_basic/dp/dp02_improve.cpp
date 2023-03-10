/*
DP--完全背包问题
二维优化版
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1010;
int n,m;
int v[N],w[N];
int f[N][N];

int main(){
    cin >> n >> m;
    for(int i =1 ;i<=n ; i++) cin >> v[i] >> w[i];
    for(int i=1;i<=n;i++)
        for(int j=0;j<=m;j++){
            // for(int k=0;k*v[i] <=j;k++)
            f[i][j] = f[i-1][j];
            //推导：将f[i][j]和f[i][j-v]进行对比得到的
            if(j>=v[i]) f[i][j] = max(f[i][j],f[i][j-v[i]]+w[i]);
            //对比01背包方程：f[i][j] = max(f[i][j],f[i-1][j-v[i]] + w[i]) 只有一个地方有区别
        }

    cout << f[n][m] << endl;    
    return 0;
}