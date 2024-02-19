/*
title: 庆功宴
Tag: 多重背包问题
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 6000;
int n,m;
int f[N];
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        int v,w,s;
        cin >> v >> w >> s;
        for(int j=m;j>=0;j--){
            for(int k=0;k<=s && k*v<=j;k++){
                f[j] = max(f[j],f[j-k*v]+k*w);
            }
        }
    }
    cout << f[m] << endl;
    return 0;
}