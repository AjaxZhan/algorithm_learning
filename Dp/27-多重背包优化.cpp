/*
title: 多重背包优化
Tag: 多重背包 二进制优化
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
// 采用“打包的思路”
const int N = 24050, M = 2010;
int n,m;
int v[N],w[N],f[N];
int main(){
    cin >> n >> m;
    int cnt = 0;;
    for(int i=1;i<=n;i++){
        int a,b,s;
        cin >> a >> b >> s;
        int k = 1;
        while(k<=s){
            cnt++;
            v[cnt] = a*k;
            w[cnt] = b*k;
            s -=k;
            k *= 2;
        }
        if(s > 0){
            cnt++;
            v[cnt] = a*s;
            w[cnt] = b*s;
        }
    } 
    n = cnt;
    for(int i=1;i<=n;i++)
        for(int j=m;j>=v[i];j--)
            f[j] = max(f[j],f[j-v[i]]+w[i]);
    cout << f[m] << endl;
    return 0;
}