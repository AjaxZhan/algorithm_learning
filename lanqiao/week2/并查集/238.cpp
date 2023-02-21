/*
title: 蓝桥杯复习
from: acwing238 银河英雄传说
Tag: 并查集
Code:
统一维护当前战舰到排头的距离：只需要d[x]-d[y]-1
相当于综合了连通块中点的数量 + 食物链
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 30010;
int t;
int p[N],s[N],d[N]; // s表示连通块中点的数量，即size。 d[x]表示x到px的距离。
int find(int x){
    if(p[x]!=x){
        int u = find(p[x]);
        d[x]+=d[p[x]]; // 递归更新距离
        p[x] = u;
    }
    return p[x];
}
int main(){
    scanf("%d",&t);
    for(int i=1;i<=N;i++){
        p[i] = i;
        s[i] = 1; // 连通块中点的数量
    }
    while(t--){
        char op[2];
        int a,b;
        scanf("%s%d%d",op,&a,&b);
        int pa =find(a), pb = find(b);
        if(*op == 'M'){
            if(pa!=pb){ // 将a接到b的后面
                d[pa] = s[pb]; //a到b的距离
                s[pb] +=s[pa]; //更新b的大小
                p[pa] = pb; //接入
            }
        }else{
            if(pa != pb) puts("-1");
            else{
                int res =abs(d[a] - d[b])-1;
                printf("%d\n",max(0,res));
            }
        }
    }
    return 0;
}