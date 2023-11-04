/*
title: 算法提高DP篇--最长上升子序列
from: acwing 1014登山
Tag: DP 线性DP
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1010;
int n;
int a[N];
int g[N],f[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);

    for(int i=1;i<=n;i++){
        f[i] = 1;
        for(int j=1;j<i;j++)
            if(a[i] > a[j]) f[i] = max(f[i],f[j]+1);
    }

    for(int i=n;i>=1;i--){
        g[i] = 1;
        for(int j=n;j>i;j--)
            if(a[i] > a[j]) g[i] = max(g[j]+1,g[i]);
    }

    int res = 0;
    for(int k=1;k<=n;k++) res = max(res,g[k]+f[k]-1);
    cout << res << endl;

    return 0;
}