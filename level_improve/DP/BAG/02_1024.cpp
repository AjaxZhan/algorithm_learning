/*
title: 装箱问题
from: acwing1024
Tag: 01BAG
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 20010;
int v[N];
int f[N];
int gv,n;
int main(){
    cin >> gv;
    cin >> n;
    for(int i=1;i<=n;i++) scanf("%d",&v[i]);
    for(int i=1;i<=n;i++){
        for(int j=gv;j>=v[i];j--){
            f[j] = max(f[j],f[j-v[i]] + v[i]); 
        }
    }
    cout <<gv - f[gv] << endl;
    return 0;
}