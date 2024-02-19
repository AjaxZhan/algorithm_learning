/*
title: 能量石
Tag: 贪心、DP
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 10010; // 时间是体积
int f[N];
struct Stone{
    int s,e,l;
    bool operator < (const Stone& W) const{
        return s * W.l < W.s * l;
    }
}stone[N];
int main(){
    int T;
    cin >> T;
    for(int c=1;c<=T;c++){
        int n = 0, m = 0;
        cin >> n;
        for(int i=0;i<n;i++){
            int s,e,l;
            cin >> s >> e >>l;
            stone[i] = {s,e,l};
            m+=s;
        }
        sort(stone,stone+n);
        memset(f,-0x3f,sizeof f);
        f[0] = 0;
        for(int i=0;i<n;i++){
            int s = stone[i].s;
            int e = stone[i].e;
            int l = stone[i].l;
            for(int j=m;j>=s;j--){
                f[j]  = max(f[j],f[j-s]+e-l*(j-s));
            }
        }
        int res = 0;
        for(int i=0;i<=m;i++) res = max(res,f[i]);
        printf("Case #%d: %d\n",c,res);
    }
    return 0;
}