/*
title: 合唱队形
from: acwing 482
Tag: LIS
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 110;
int a[N],g[N],f[N];
int n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int res = 0;
    //正向LIS
    for(int i=1;i<=n;i++){
        f[i] = 1; //表示空集的情况
        for(int j=1;j<i;j++){
            if(a[j] < a[i]) f[i] = max(f[i],f[j]+1);
        }
    }
    //反向LIS
    for(int i=n;i>=1;i--){
        g[i] = 1;
        for(int j=n;j>i;j--){
            if(a[j] < a[i]) g[i] = max(g[i],g[j]+1);
        }
    }
    for(int i=1;i<=n;i++) res = max(res,f[i] + g[i] - 1);
    printf("%d\n",n-res);
    

    return 0;
}