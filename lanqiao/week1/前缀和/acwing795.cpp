/*
title:蓝桥杯备赛复习
from:AcWing 795. 前缀和
Tag:前缀和 模板
Code: https://www.acwing.com/problem/content/797/
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100010;
int n;
int m;
int s[N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&s[i]);
        s[i]+=s[i-1];
    }
    while(m--){
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",s[r]-s[l-1]);
    }
    return 0;
}