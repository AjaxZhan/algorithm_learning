/*
title: 方格取数
Tag: dp 数字三角形
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 15;
int n;
int f[N+N][N][N];
int w[N][N];
int main(){
    scanf("%d",&n);
    int a,b,c;
    while(cin >> a>> b >> c,a||b||c) w[a][b] = c;
    for(int k =2; k<=n+n;k++)
        for(int i1=1;i1<=n;i1++)
            for(int i2=1;i2<=n;i2++)
            {
                // 这种枚举都要判断下范围的合法性
                int j1 = k-i1, j2 = k-i2;
                if(j1>=1 && j1<=n && j2>=1 && j2<=n){
                    int s = w[i1][j1];
                    if(i1 != i2) s+= w[i2][j2];
                    f[k][i1][i2] = max(f[k][i1][i2],f[k-1][i1-1][i2-1]+s);
                    f[k][i1][i2] = max(f[k][i1][i2],f[k-1][i1-1][i2]+s);
                    f[k][i1][i2] = max(f[k][i1][i2],f[k-1][i1][i2-1]+s);
                    f[k][i1][i2] = max(f[k][i1][i2],f[k-1][i1][i2]+s);
                }
            }
    printf("%d\n",f[n+n][n][n]);
    return 0;
}