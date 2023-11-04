/*
title: 二维费用的背包问题
from: acwing 8
Tag: 二维费用 背包问题
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 110;
int n,V,M;
int f[N][N];
int w[N];
int main(){
    cin >> n >> V >> M;
    for(int i=0;i<n;i++){
        int v,m;
        cin >> v >> m >> w[i];
        for(int j=V;j>=v;j--){
            for(int k=M;k>=m;k--){
                f[j][k] = max(f[j][k],f[j-v][k-m] + w[i]);
            }
        }
    }
    cout << f[V][M] << endl;

    return 0;
}