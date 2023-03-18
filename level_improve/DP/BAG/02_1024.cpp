/*
title: 装箱问题
from: acwing 1024
Tag: 01BAG
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 20010;
int n;
int V;
int f[N];
int main(){
    cin >> V;
    cin >> n;
    for(int i=0;i<n;i++){
        int v;
        cin >> v;
        for(int j = V;j>=v;j--){
            f[j] = max(f[j],f[j-v] + v);
        }
    }
    cout << V - f[V] << endl;
    return 0;
}