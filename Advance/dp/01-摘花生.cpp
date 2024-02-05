/*
title: 摘花生
Tag: dp 数字三角形
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 110;
int n,m;
int w[N][N]; // 花生数量
int f[N][N]; // f[i][j] 表示从 (1,1) 到 (i,j) 的最大花生数量
int main(){
    int batch;
    scanf("%d",&batch);
    while(batch--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&w[i][j]);
        
        // 枚举所有状态
        // 线性DP一般按照下标顺序就是拓扑顺序
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                f[i][j] = max(f[i-1][j],f[i][j-1]) + w[i][j];
        
        printf("%d\n",f[n][m]);
    }

    return 0;
}