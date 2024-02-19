/*
title: 股票IV
Tag: 状态机DP
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10, M = 110, INF = 0x3f3f3f3f;
int f[N][M][2];
int w[N];
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    
    memset(f,-0x3f,sizeof f);
    for(int i=0;i<=n;i++) f[i][0][0] = 0;

    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f[i][j][0] = max(f[i-1][j][0],f[i-1][j][1]+w[i]);
            f[i][j][1] = max(f[i-1][j][1],f[i-1][j-1][0]-w[i]);
        }
    }

    // 最后手中必然无货，枚举交易次数
    int res = 0;
    for(int i=0;i<=m;i++) res = max(res,f[n][i][0]);

    printf("%d\n",res);
    return 0;
}