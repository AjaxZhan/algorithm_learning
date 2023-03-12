/*
title: Kruskal模板
from:
Tag:
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1000010;
int n,m;
int p[N];
struct Edge{
    int a,b,w;
    bool operator<(const Edge & e)const{
        return w < e.w;
    }
}edges[N];
int find(int x){
    if(x !=p[x]) p[x] = find(p[x]);
    return p[x];
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a, b,w;
        scanf("%d%d%d",&a,&b,&w);
        edges[i] = {a,b,w};
    }
    sort(edges,edges+m);
    //初始化并查集
    for(int i = 1; i <= n;i++) p[i] = i;
    int res = 0, cnt = 0;
    for(int i =0;i<m;i++){
        int a = edges[i].a,b = edges[i].b , w= edges[i].w;
        a = find(a);
        b = find(b);
        if(a!=b){
            res +=w;
            cnt++;
            p[a] = b;
        }
    }
    if(cnt < n-1) puts("impossible");
    else printf("%d\n",res);
    return 0;
}