/*
title: 分组背包
Tag: dp 背包问题
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N =110;
int w[N],v[N];
int f[N];
int main(){
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        int s;
        cin >> s;
        for(int j=1;j<=s;j++) cin >> v[j] >> w[j];
        for(int j=m;j>=0;j--){
            for(int k=1;k<=s;k++)
                if(j >= v[k])
                    f[j] = max(f[j],f[j-v[k]]+w[k]);
        }
    }
    cout << f[m] << endl;
    return 0;
}