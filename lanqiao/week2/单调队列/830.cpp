/*
title: 蓝桥杯复习
from: acwing830 单调栈.
Tag: 单调栈
Code:
单调栈：给一个序列，求每一个数左边离它最近的数比其小的数。
如： 3 4 2 7 5
ans：-1 3 0-1 2 2
暴力：两重循环
性质；如果存在x < y 并且 a[x]>a[y] 显然a[x]不会是答案。所以stack存在单调性。
因此，只要栈顶>=a[i]，就一直pop，直到一个 < a[i],就是答案。
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100010;
int stk[N],tt;
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        while(tt && stk[tt] >= x) tt--;
        if(!tt) cout << "-1 ";
        else cout << stk[tt] << " ";
        stk[++tt] = x;
    }

    return 0;
}