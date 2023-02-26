/*
title: 蓝桥杯备赛
from: acwing 1270 维护数列区间最大值
Tag: 线段树
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;
const int N = 1e5+10;
int n,m;
int w[N]; //原序列
struct Node{
    int l,r;
    int maxv;
}tr[N*4];

//这题的pushup可以写到其它函数内

void build(int u ,int l ,int r){
    if( l ==r ) tr[u] = {l,r,w[r]};
    else{
        tr[u] = {l,r}; //初始化属性
        int mid = l + r >> 1 ;
        build(u << 1, l , mid);
        build(u <<1 | 1, mid+1,r);
        //pushup
        tr[u].maxv = max(tr[u <<1 ].maxv,tr[u<<1 |1 ].maxv); 
    }
}   

int query(int u , int l ,int r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].maxv;
    int mid = tr[u].l + tr[u].r >> 1;
    int maxv = INT_MIN; //INT_MIN在cmath内,表示整数最小值
    if(l <=mid) maxv = max(maxv,query(u << 1 , l ,r));
    if(r > mid ) maxv = max(maxv,query(u <<1 |1 , l,r));
    return maxv;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);

    build(1,1,n);
    
    int l,r;
    while(m--){
        scanf("%d%d",&l,&r);
        printf("%d\n",query(1,l,r));
    }
    return 0;
}