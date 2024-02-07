/*
title: 01背包求方案数II-最优解方案数
Tag: 01背包 方案数
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1010,mod = 1e9+7;
int n,m;
int f[N],g[N];
int main(){
    cin >> n >> m;
    // 体积恰好是j
    memset(f,-0x3f,sizeof f);
    f[0] = 0;
    g[0] = 1;
    for(int i=1;i<=n;i++){
        int v,w;
        cin >> v >> w;
        for(int j=m;j>=v;j--){
            int maxv = max(f[j],f[j-v]+w);
            int cnt = 0;
            if(maxv == f[j]) cnt += g[j];
            if(maxv == f[j-v]+w) cnt += g[j-v];
            g[j] = cnt % mod;
            f[j] = maxv;
        }
    }
    // 先求出最大值是多少
    int res = 0;
    for(int i=0;i<=m;i++) res = max(res,f[i]);
    int cnt = 0;
    // 统计方案数
    for(int i=0;i<=m;i++)
        if(res == f[i])
            cnt = (cnt + g[i]) % mod;
    
    cout << cnt << endl;


    return 0;
}