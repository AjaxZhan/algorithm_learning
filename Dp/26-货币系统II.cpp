/*
title: 货币系统II
Tag: 线性代数 dp 
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 25010;
int n;
int f[N];
int a[N];
int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        for(int i=0;i<n;i++) cin >> a[i];
        sort(a,a+n);

        memset(f,0,sizeof f);
        f[0] = 1;
        int m = a[n-1];

        int res = 0;
        for(int i=0;i<n;i++){
            if(!f[a[i]]) res++;
            for(int j=a[i];j<=m;j++)
                f[j] += f[j-a[i]];
        }
        cout << res << endl;
    }
    return 0;
}