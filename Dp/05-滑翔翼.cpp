/*
title: 怪盗基德的滑翔翼
Tag: dp 最长上升子序列
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 110;
int a[N];
int f[N];
int n;
int main(){
    int batch;
    scanf("%d",&batch);
    while(batch--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        // 正向求LIS
        int res = 0;
        for(int i=1;i<=n;i++){
            f[i] = 1;
            for(int j=1;j<=i-1;j++)
                if(a[j]<a[i])
                    f[i] = max(f[i],f[j]+1);
            res = max(res,f[i]);
        }
        // 反向求LIS
        for(int i=n;i>=1;i--){
            f[i] = 1;
            for(int j=n;j>=i+1;j--)
                if(a[j]<a[i])
                    f[i] = max(f[i],f[j]+1);
            res = max(res,f[i]);
        }
        printf("%d\n",res);
    }
    return 0;
}