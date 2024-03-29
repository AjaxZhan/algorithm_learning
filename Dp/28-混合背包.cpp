/*
title: 混合背包
Tag: dp
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1010;
int n,m;
int f[N];
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        int v,w,s;
        cin >> v >> w >>s;
        if(s == 0){ // 背包
            for(int j=v;j<=m;j++)
                f[j] = max(f[j],f[j-v]+w);
        }else{
            // 01背包是特殊的多重背包
            if(s == -1) s = 1;
            for(int k=1;k<=s;k*=2){
                for(int j=m;j>=k*v;j--)
                    f[j] = max(f[j],f[j-k*v]+k*w);
                s-=k;
            }
            if(s >0){
                for(int j=m;j>=s*v;j--)
                    f[j] = max(f[j],f[j-s*v]+s*w);
            }
                
        }
    }
    cout << f[m] << endl;
    return 0;
}