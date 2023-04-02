/*
title: 石子合并
from: 
Tag: 区间DP
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 310;
int n;
int f[N][N];
int s[N];
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> s[i];
        s[i]+=s[i-1];
    }
    //枚举区间
    for(int len =2; len <=n;len++){
        for(int i=1;i + len -1 <=n;i++){
            int j = i + len -1;
            f[i][j] = 1e8;
            for(int k=i;k<j;k++){
                //枚举分界点
                f[i][j] = min(f[i][j],f[i][k]+f[k+1][j] + s[j]-s[i-1]);
            }
        }
    }

    printf("%d\n",f[1][n]);
    return 0;
}