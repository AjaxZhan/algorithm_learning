/*
title: 开心的金明
Tag: 01背包
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 32000;
int f[N];
int n,m;
int main(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int v, w;
        cin >> v >> w;
        for(int j=n;j>=v;j--){
            f[j] = max(f[j],f[j-v]+w*v);
        }
    }
    cout << f[n] << endl;
    return 0;
}