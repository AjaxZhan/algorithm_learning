/*
title: 算法提高DP篇--最长上升子序列模型
from: acwing 1017 怪盗基德的滑翔翼
Tag: DP 线性DP 最长上升子序列
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 110;
int k;
int n;
int h[N];
int f[N];
int main(){
    scanf("%d",&k);
    while(k--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&h[i]);
        
        int res = 0;
        //正向求解
        for(int i=1;i<=n;i++)
        {
            f[i] = 1;
            for(int j=1;j<i;j++)
                if(h[j] < h[i]) f[i] = max(f[i],f[j]+1);
            
            res = max(res,f[i]);
        }
        //反向求解
        for(int i=n;i>=1;i--)
        {
            f[i] = 1;
            for(int j=n;j>i;j--)
                if(h[j] < h[i]) f[i] = max(f[i],f[j]+1);
            
            res = max(res,f[i]);
        }
        printf("%d\n",res);
    }
    return 0;
}