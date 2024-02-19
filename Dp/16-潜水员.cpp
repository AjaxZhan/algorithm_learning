/*
title: 潜水员
Tag: dp 01背包 二维背包
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 22,M = 80;
int f[N][M];
int n,m,siz;
int main(){

    cin >> n >> m >> siz;
    memset(f,0x3f,sizeof f);
    f[0][0] = 0;
    while(siz--){
        int v1,v2,w;
        cin >> v1 >> v2 >> w;
        for(int i=N-1;i>=0;i--)
            for(int j=M-1;j>=0;j--)
                f[i][j] = min(f[i][j],f[max(i-v1,0)][max(j-v2,0)]+w);
    }
    int res = 1e9;
    for(int i=n;i<N;i++)
        for(int j=m;j<M;j++)
            res = min(res,f[i][j]);
    cout << res << endl;
    return 0;
}