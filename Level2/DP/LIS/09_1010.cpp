/*
title: 拦截导弹
from: acwing1010
Tag: LIS 贪心
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1010;
int n;
int q[N];
//g存储的是现有的子序列的结尾
int f[N],g[N];
int main(){
    while(cin >> q[n]) n++; //读取数，并且记录个数
    int res=  0;
    //LIS
    for(int i=0;i<n;i++){
        f[i] = 1;
        for(int j=0;j<i;j++){
            if(q[j] >= q[i]) f[i] = max(f[i],f[j]+1); //这里是单调下降
        }
        res = max(res,f[i]);
    }
    cout << res << endl;
    //第二问：贪心。贪心策略：在所有的子序列中找到结尾大于当前数的最小值，加入到后面。否则创建一个序列。
    int cnt = 0; // 记录子序列个数
    for(int i=0;i<n;i++){
        int k = 0; //指针，表示寻找的数
        while(k < cnt && g[k]<q[i]) k++;
        g[k] = q[i];
        if(k >=cnt) cnt++; //找不到新序列

    }
    cout << cnt << endl;
    return 0;
}