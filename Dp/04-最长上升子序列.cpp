/*
title: 最长上升子序列
Tag: dp 最长上升子序列
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1010;
int n;
int a[N]; // 序列
int f[N]; // 状态 
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        f[i] = 1;
        for(int j=1;j<=n-1;j++)
            if(a[j] < a[i])
                f[i] = max(f[i],f[j]+1);
    }
    int res = 0;
    for(int i=1;i<=n;i++) res = max(res,f[i]);
    printf("%d\n",res);
    return 0;
}