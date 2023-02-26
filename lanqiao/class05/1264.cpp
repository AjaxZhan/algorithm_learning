/*
title: 蓝桥备考
from: acwing 1264 动态求连续区间和
Tag: 树状数组
Code: 很模板化的代码
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100000  + 10;
int n,m;
int c[N];
int lowbit(int x){
    return x & -x;
}
int query(int final){ // 求1 - x
    int res = 0;
    for(int i= final ;i >0;i-=lowbit(i)) res+=c[i];
    return res;
}   
void add(int a , int v){
    for(int i = a;i <=n;i+= lowbit(i)) c[i]+=v;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int v;
        scanf("%d",&v);
        add(i, v);
    } 
    while(m--){
        int op , a, b;
        scanf("%d%d%d",&op,&a,&b);
        if( op == 0){
            //前缀和
            printf("%d\n",query(b) - query(a -1));
        }else add(a,b);
    }

    return 0;
}