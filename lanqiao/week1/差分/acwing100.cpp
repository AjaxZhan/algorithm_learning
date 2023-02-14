/*
title:蓝桥杯备赛
from:acwing 100. 增减序列 IncDec序列
Tag: 差分 贪心
Code:
思路：
    差分的定义 b[i] = a[i] - a[i-1]; 其中b[1]可以为任意常数。
    利用性质，题目把a数组变为相同，转化为B数组从b2--bn都为0即可。
    贪心：
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100010;
int n;
typedef long long LL;
LL a[N];

int main(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=n;i>1;i--) a[i]-=a[i-1]; // 求差分
    //计算所有的正数/负数
    LL pos = 0, neg = 0;
    for(int i=2;i<=n;i++)
        if(a[i] > 0) pos+=a[i];
        else neg-=a[i];
    
    cout << min(pos,neg) + abs(pos- neg) << endl;

    cout << abs(pos - neg) + 1 << endl;

    return 0;
}