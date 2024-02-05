/*
title: 最低通行费
Tag: dp 数字三角形
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 110,INF=1e9;
int n;
int w[N][N]; // 路费
int f[N][N]; // f[i][j] 表示从 (1,1) 到 (i,j) 的最小路费
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            scanf("%d",&w[i][j]);
            // 这里是最小值，所以要防止从第0列和行更新过来
            if(i == 1 && j == 1) f[i][j] = w[i][j];
            else{
                f[i][j] = INF;
                if(i > 1) f[i][j] = min(f[i-1][j]+ w[i][j],f[i][j]) ;
                if(j > 1) f[i][j] = min(f[i][j-1] + w[i][j],f[i][j]);
            }
        }
    printf("%d\n",f[n][n]);
    return 0;
}