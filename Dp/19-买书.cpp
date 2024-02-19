/*
title: 买书
Tag: 完全背包
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1005;
int n;
int v[4] = {10,20,50,100};
int f[N];
int main(){
    cin >> n;
    f[0] = 1;
    for(int i=0;i<4;i++)
        for(int j=v[i];j<=n;j++)
            f[j]+=f[j-v[i]];
    cout << f[n] << endl;
    return 0;
}