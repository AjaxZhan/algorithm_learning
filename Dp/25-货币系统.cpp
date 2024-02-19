/*
title: 货币系统(和买书思路一样)
Tag: 完全背包
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int M = 3010;
int n,m;
long long f[M];
int main(){
    cin >> n >> m;
    f[0] = 1; // 可能忘记初始化
    for(int i=1;i<=n;i++){
        int v;
        cin >> v;
        for(int j=v;j<=m;j++)
            f[j] += f[j-v];
    }
    cout << f[m] << endl;
    return 0;
}