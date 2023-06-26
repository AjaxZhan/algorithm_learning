/*
title: 字符串前缀哈希法
from: 841 字符串哈希
Tag: 字符串哈希
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef unsigned long long ULL; // 代替模2的64次方
const int N = 100010,P = 131;
int n,m;
char str[N];
ULL h[N],p[N]; // h数组是前i个字母的哈希值，p数组是多少次幂的预处理
ULL get(int l , int r){
    return h[r] - h[l-1]*p[r-l+1]; // 获取任意区间子串的哈希值
}

int main(){
    scanf("%d%d",&n,&m);
    scanf("%s",str+1);
    p[0] = 1;
    for(int i=1;i<=n;i++){
        p[i] = p[i-1]*P; // 初始化P数组
        h[i] = h[i-1] *P + str[i];
    }
    while(m--){
        int l1,r1,l2,r2;
        scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
        if(get(l1,r1) == get(l2,r2)) puts("Yes");
        else puts("No");
    }
    return 0;
}