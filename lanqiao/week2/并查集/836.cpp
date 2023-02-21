/*
title: 合并集合
from: acwing 836 合并集合
Tag: 并查集
Code:
并查集复习；并查集支持以O(1)的时间执行合并和查询操作。
基本原理：用树的形式维护所有编号，p[x]存储父节点。树根p[x] = x;
合并：p[x] = y;
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m;
const int N = 100010;
int p[N];
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) p[i] = i; // 最开始每个点是一个集合
    while(m--){
        int a,b;
        char op[2];
        scanf("%s%d%d",&op,&a,&b);
        if(*op == 'M'){
           p[find(a)] =  find(b);  
        }else{
            //查询
            if(find(a) == find(b)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}