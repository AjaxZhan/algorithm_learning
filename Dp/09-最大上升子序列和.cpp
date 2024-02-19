/*
title: 最大升序子序列和
Tag: dp 最长上升子序列
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1010;
int n;
int a[N], f[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int res = 0;
    for(int i=1;i<=n;i++){
        f[i] = a[i];
        for(int j=1;j<=i-1;j++)
            if(a[j] < a[i])
                f[i] = max(f[i],f[j]+a[i]);
        res = max(res,f[i]);
    }
    printf("%d\n",res);
    return 0;
}