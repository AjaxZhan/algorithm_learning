/*
title: 递增三元组 前缀和写法
from: acwing 1236
Tag: 前缀和 枚举
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100010;
typedef long long LL;
LL res;
int a[N],b[N],c[N];
int n;
int as[N]; //在a中有多少个数 < bi
int cs[N]; //在c中有多少个数  > bi
int cnt[N];//每个数出现多少次
int s[N]; // 从0-i出现的个数

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]),a[i]++; // 前缀和处理的时候，防止这个数是0
    for(int i=0;i<n;i++) scanf("%d",&b[i]),b[i]++;
    for(int i=0;i<n;i++) scanf("%d",&c[i]),c[i]++;

    //处理ai
    for(int i=0;i<n;i++) cnt[a[i]]++;
    for(int i=1;i<N;i++) s[i] = s[i-1]+cnt[i]; //前缀和，注意是N
    for(int i=0;i<n;i++) as[i] = s[b[i]-1];

    memset(cnt,0,sizeof cnt);
    memset(s,0,sizeof s);
    //处理ci
    for(int i=0;i<n;i++) cnt[c[i]]++;
    for(int i=1;i<N;i++) s[i] = s[i-1]+cnt[i]; //前缀和，注意是N
    for(int i=0;i<n;i++) cs[i] = s[N-1]- s[b[i]];

    for(int i=0;i<n;i++) res+=(LL)as[i]*cs[i];

    cout << res << endl;



    return 0;
}