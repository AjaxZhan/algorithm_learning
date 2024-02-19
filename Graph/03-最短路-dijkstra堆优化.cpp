/*
title: dijkstra堆优化
Tag: 最短路 dijkstra
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#define x first
#define y second
using namespace std;
typedef pair<int,int> PII;
const int N = 151100;
int n,m;
int h[N],e[N],ne[N],w[N],idx;
int dist[N];
bool st[N];
void add(int a, int b, int c){
    w[idx] = c; 
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
int dijkstra(){
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    // pair存储：距离-节点编号
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,1});
    while(heap.size()){
        // 找到距离最小的点
        auto t = heap.top();
        heap.pop();
        int ver = t.y, distance = t.x;
        if(st[ver]) continue; // 标记过
        st[ver] = true;
        for(int i=h[ver];~i;i=ne[i]){
            int j = e[i];
            if(dist[j] > distance + w[i]){
                dist[j] = distance + w[i];
                heap.push({dist[j],j});
            }
        }
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    else return dist[n];
}
int main(){
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof h);

    while(m--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
    }
    printf("%d\n",dijkstra());

    return 0;
}