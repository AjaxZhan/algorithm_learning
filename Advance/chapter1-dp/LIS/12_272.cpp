/*
title: 最长公共上升子序列
from: acwing 272
Tag: DP LIS
Code:优化的版本
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 3010;
int n;
int a[N],b[N];
int f[N][N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    //用变量存储某个前缀的最大值
    
    for(int i=1;i<=n;i++){
        int maxv = 1; //表示1到j-1满足bk < bj 的最大值。
        for(int j=1;j<=n;j++){
            f[i][j] = f[i-1][j];
            if(a[i] == b[j])
                f[i][j] = max(f[i][j],maxv);
            if(b[j] < a[i]) maxv = max(maxv,f[i-1][j]+1);
        }
    }
    int res = 0;
    for(int i=1;i<=n;i++) res = max(res, f[n][i]);
    printf("%d\n",res);
    
    return 0;
}