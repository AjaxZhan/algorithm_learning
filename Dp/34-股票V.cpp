/*
title:  股票V
Tag: 状态机DP
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f;
int n;
int f[N][3];
int w[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);

    // 初始化
    memset(f,-0x3f,sizeof f);
    f[0][2] = 0;
    for(int i=1;i<=n;i++){
        f[i][0] = max(f[i-1][0],f[i-1][2]-w[i]);
        f[i][1] = f[i-1][0]+w[i];
        f[i][2] = max(f[i-1][2],f[i-1][1]);
    }

    printf("%d\n",max(f[n][1],f[n][2]));
    return 0;
}