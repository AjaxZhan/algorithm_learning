/*
title:蓝桥杯备赛复习
from:Acwing3956  截断数组
Tag:枚举 前缀和 周赛
Code: https://www.acwing.com/problem/content/3959/
思路：
1. 总和必须是3的倍速。否则不可能分成三份。
2. 枚举第二刀：
    区间：[1,j] [j+1,i-1] [i, n]
    最后一段：Sn - Si-1 = sum/3
    第一段：1<=j<=i-2 即两段都非空 && Sj=sum/3
注意：
    答案大概是C(n-1)取2，会爆int，需要用long long
    数据范围是1e5，时间复杂度控制在O(N)左右
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100010;
typedef long long LL;
int s[N];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int a = 0;
        scanf("%d",&a);
        s[i] = s[i-1] + a;
    }

    if(s[n]%3){
        puts("0");
        return 0;
    }
    LL res = 0;

    for(int i=3,cnt =0;i<=n;i++){ // cnt表示前面多少个j满足
        if(s[i-2] == s[n]/3 ) cnt++;
        if(s[n]-s[i-1] == s[n]/3)   res+=cnt;
    }
    cout << res << endl;

    return 0;
}