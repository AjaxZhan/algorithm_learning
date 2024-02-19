/*
title: 大盗阿福
Tag: dp 状态机DP
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100010 , INF = 0x3f3f3f3f;
int n;
int w[N],f[N][2];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&w[i]);
        // 入口
        f[0][0] = 0 , f[0][1] = -INF;
        for(int i=1;i<=n;i++){
            f[i][0] = max(f[i-1][0],f[i-1][1]);
            f[i][1] = f[i-1][0] + w[i];
        }
        printf("%d\n",max(f[n][0],f[n][1]));
    }
    
    return 0;
}