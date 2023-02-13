/*
title:蓝桥杯备赛复习
from:AcWing 1230. K倍区间
Tag:前缀和 HNOI2003
Code: https://www.acwing.com/problem/content/1230/
思路：
    复杂度：数据范围是1E5 -- O(N) / O(NLOGN)
    第二重循环优化：
        在1-R之间找到多少个L，满足S[R]-S[L-1]%K ==0
        在0-R-1之间找到多少个L，满足S[R]-S[L]%K ==0
        即每次查询：有多少个S[L]与S[R]余数相同。
        方案：开一个cnt[i]表示多少个s[i]余数是i的数有多少个
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100010;
typedef long long LL;
int n,k;
LL s[N],cnt[N];//cnt存放余数
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&s[i]);
        s[i]+=s[i-1];
    }
    LL res = 0;
    
    cnt[0] = 1;
    for(int i=1;i<=n;i++){
        res+=cnt[s[i]%k];
        cnt[s[i]%k]++;
    }
    printf("%lld\n",res);
    return 0;
}