/*
title: 二叉树
from: acwing 3555
Tag: LCA DFS
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1010;
int t,n,m;
//二叉树
int l[N],r[N],p[N];
//预处理每个点到根节点的距离
int dist[N];
int get_lca(int a, int b){
    if(dist[a] > dist[b]) swap(a,b);
    while(dist[b] > dist[a]) b= p[b];
    while(a!=b) a =p[a], b = p[b];
    return a;
}
void dfs(int u , int d){
    dist[u] = d;
    if(l[u] != -1) dfs(l[u],d+1);
    if(r[u] != -1) dfs(r[u],d+1);
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            //对左右树赋值
            l[i] = a;
            r[i] = b;
            if(a != -1) p[a] = i;
            if(b != -1) p[b] = i;
        }
        dfs(1,0);
        while(m--){
            int a,b;
            scanf("%d%d",&a,&b);
            int lca = get_lca(a,b);
            printf("%d\n",dist[a] + dist[b] - 2 * dist[lca]);
        }
    }
    return 0;
}