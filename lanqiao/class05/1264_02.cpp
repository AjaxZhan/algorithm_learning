/*
title: 蓝桥杯复习
from: 1264
Tag: 线段树
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100010;
int n,m;
int w[N];
struct Node{
    int l,r,sum;
}tr[4*N];
//用左右儿子信息更新当前节点
void pushup(int u ){
    tr[u].sum = tr[u << 1 ].sum  + tr[u << 1 | 1].sum;
}
//在一段区间初始化线段树
void build(int u, int l , int r){
    //叶节点，直接更新
    if( l == r) tr[u] = {l,r,w[u]};
    else{
        tr[u] = {l,r}; 
        int mid = l + r >> 1; 
        //建构左右子树
        build(u << 1 ,l,mid);
        build(u << 1 | 1,mid+1,r);
        pushup(u); // 使用左右儿子信息更新当前结点
    }
}
//询问和，根节点编号 ，查询区间
int query(int u , int l ,int r){
    if(tr[u].l >=l && tr[u].r <= r) return tr[u].sum; //如果区间被包含
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        int sum = 0;
        if( l <= mid ) sum =query(u<<1,l,r); //和左边有交集
        if(r > mid) sum = query(u << 1 | 1 , l,r ); //和右边有交集
        return sum;
    }
}

//根节点编号，插入位置，插入的值
void modify(int u , int x, int v){
    if(tr[u].l == tr[u].r) tr[u].sum+=v;
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(x <=mid) modify(u<<1,x,v); //左半边
        else modify(u << 1 | 1,x,v); // 右半边
        pushup(u);
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
        build(1,1,n);
    } 
    while(m--){
        int op , a, b;
        scanf("%d%d%d",&op,&a,&b);
        if( op == 0){
            //前缀和
            printf("%d\n",query(1,a,b));
        }else modify(1,a,b);
    }
    return 0;
}