/*
title: 采草药
from: acwing 423
Tag: 01BAG 
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1010;
int T,M;
int f[N]; // 状态
int v[N];
int w[N];
int main(){
    scanf("%d%d",&T,&M);
    for(int i=1;i<=M;i++){
        scanf("%d%d",&v[i],&w[i]);
    }
    for(int i=1;i<=M;i++){
        for(int j = T;j>=v[i];j--){
            f[j] = max(f[j],f[j-v[i]] + w[i]);
        }
    }
    //01背包
    cout << f[T] << endl;
    return 0;
}