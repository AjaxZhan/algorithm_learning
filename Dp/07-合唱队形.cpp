/*
title: 合唱队形
Tag: dp 最长上升子序列
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1010;
int n;
int a[N];
int f[N],g[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    // 预处理出f和g
    for(int i=1;i<=n;i++){
        f[i] = 1;
        for(int j=1;j<=i-1;j++)
            if(a[j]<a[i])
                f[i] = max(f[i],f[j]+1);
    }
    for(int i=n;i>=1;i--){
        g[i] = 1;
        for(int j=n;j>=i+1;j--)
            if(a[j]<a[i])
                g[i] = max(g[i],g[j]+1);
    }
    int res = 0;
    for(int i=1;i<=n;i++){
        // 记得减去重复计算部分
        res = max(res,f[i]+g[i]-1);
    }
    printf("%d\n",n-res);
    return 0;
}