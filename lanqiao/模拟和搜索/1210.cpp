/*
title: 连号区间数
from: acwing 1210
Tag: 模拟 优化
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100010;
const int INF = 0x3f3f3f3f;
int n;
int a[N];
int maxnum ,minnum;
int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    int res = 0;
    for(int i=0;i<n;i++){
        maxnum = -INF,minnum = INF;
        for(int j=i;j<n;j++){
            maxnum = max(maxnum,a[j]);
            minnum = min(minnum,a[j]);
            if(maxnum-minnum == j-i){
                res++;
                continue;
            }
        }
    }
    cout << res << endl;
    return 0;
}