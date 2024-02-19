/*
title: 数字组合
Tag: 01背包 dp 方案数
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 10010;
int f[N];
int n,m;
int main(){
    cin >> n >> m;
    f[0] = 1;
    for(int i=1;i<=n;i++){
        int v;
        cin >> v;
        for(int j=m;j>=v;j--){
            f[j] += f[j-v];
        }
    }
    cout << f[m] << endl;
    return 0;
}