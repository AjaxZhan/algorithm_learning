/*
title: 蓝桥杯复习
from: acwing837 连通块中点的数量
Tag: 并查集
Code:
给定包含n个点的无向图，初始图中没有边，执行三种操作：连接、询问是否同一个连通块、询问连通块中点的数量
在原来并查集基础上，合并的时候加个cnt就行了。
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100010;
int n,m;
int p[N];
int cnt[N]; //存储连通块中点的数量，在根节点存储
int find(int x){
    if(p[x]!=x) p[x] = find(p[x]);
    return p[x];
}
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        p[i] = i;
        cnt[i] = 1;
    }
    while(m--){
        string op;
        int a,b;
        cin >> op;
        if(op == "C"){
            scanf("%d%d",&a,&b);
            a  = find(a);
            b = find(b);
            if(a != b){
                p[a] = b;
                cnt[b] +=cnt[a];
            }
        }else if(op == "Q1"){
            scanf("%d%d",&a,&b);
            if(find(a) == find(b)) puts("Yes");
            else puts("No");
        }else{ // Q2询问连通块中点的数量
            scanf("%d",&a);
            cout << cnt[find(a)] << endl;
        }
    }
    return 0;
}