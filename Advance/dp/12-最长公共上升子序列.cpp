/*
title: 最长公共上升子序列
Tag: LIS DP 公共子序列
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

    // 未优化版本，O^3
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         f[i][j] = f[i-1][j];
    //         if(a[i]==b[j]){
    //             int maxv = 1;
    //             for(int k=1;k<=j-1;k++){
    //                 if(b[k] < b[j]){
    //                     maxv = max(maxv,f[i-1][k]+1);
    //                 }
    //                 f[i][j] = max(f[i][j],maxv);
    //             }
    //         }
    //     }
    // }
    // 代码优化，O^2
    for(int i=1;i<=n;i++){
        int maxv = 1;
        for(int j=1;j<=n;j++){
            f[i][j] = f[i-1][j];
            if(a[i]==b[j])
                f[i][j] = max(f[i][j],maxv);
            if(b[j]<a[i]) maxv = max(maxv,f[i-1][j]+1);
        }
    }
    int res = 0;
    for(int i=1;i<=n;i++){
        res = max(res,f[n][i]);
    }
    printf("%d\n",res);
    
    return 0;
}