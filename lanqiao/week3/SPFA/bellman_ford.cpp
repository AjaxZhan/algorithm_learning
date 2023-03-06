/*
title: 复习Bellman_Ford算法
from: acwing 853
Tag:
Code:
适合最多不经过K条边的最短路。
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 510;
const int M = 10010;
const int INF = 0x3f3f3f3f;
int n,m,k;
int dist[N];
int backup[N];
struct Node{
    int a,b,w;
}edges[M];
int bellman_ford(){
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    for(int i=0;i<k;i++){ //迭代K次，表示从1到n最多经过K次的最短路
        memcpy(backup , dist, sizeof dist);
        //遍历所有的边
        for(int i=0;i<m;i++){
            int a = edges[i].a, b = edges[i].b, w= edges[i].w;
            dist[b] = min(dist[b],backup[a] + w); //注意这里是用上一次迭代的结果来更新
        }
    }
    if(dist[n] > INF / 2) return -INF; //这里真的有可能是答案是-1，所以最好不要返回-1.
    return dist[n];
}
int main(){
    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        int a, b,c;
        scanf("%d%d%d",&a,&b,&c);
        edges[i] = {a,b,c};
    }
    int res = bellman_ford();
    if(res == -INF) puts("impossible");
    else cout << res << endl;
    return 0;
}