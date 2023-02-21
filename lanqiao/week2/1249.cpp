/*
title: 蓝桥杯复习
from: acwing 1249. 亲戚
Tag: 并查集
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 20010;
int n,m,q;
int p[N];
int find(int x){
    if(p[x]!=x) p[x] = find(p[x]);
    return p[x];
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) p[i] = i;
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        int pa = find(a),pb = find(b);
        p[pa] = pb;
    }
    scanf("%d",&q);
    while(q--){
        int a,b;
        scanf("%d%d",&a,&b);
        int pa = find(a), pb = find(b);
        if(pa == pb) puts("Yes");
        else puts("No");
    }
    return 0;
}