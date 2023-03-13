/*
title:
from:
Tag:
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 110;
const int M = 220;
int n,m;
struct Edge{
    int a,b,w;
    bool operator<(const Edge& tt)const{
        return w < tt.w;
    }
}edges[M];
int p[N];
int find(int x){
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];  
}
int main(){
    int res = 0;
    cin >> n >> m;
    //初始化并查集
    for(int i=1;i<=n;i++) p[i] = i;
    for(int i=0;i<m;i++){
        int a, b,w;
        cin >> a >> b >> w;
        edges[i] = {a,b,w};
    }
    sort(edges,edges+m);

    for(int i=0;i<m;i++){
        int a = find(edges[i].a);
        int b = find(edges[i].b);
        int w = edges[i].w;
        if(a!=b) p[a] = b;
        else res+=w;  //在去掉的时候统计
    }
    cout << res << endl;
    return 0;
}