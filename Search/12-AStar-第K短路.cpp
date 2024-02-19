/*
title: 第K短路
Tag: A*算法
*/
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;

const int N = 1010, M = 200010;
int n, m, S, T, K; // 起点、终点、第K短路
// 邻接表，要建立反图
int h[N], rh[N], e[M], w[M], ne[M], idx;
// 距离
int dist[N], cnt[N];
// dijkstra判重数组
bool st[N];

void add(int h[], int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

// dijkstra预处理估价函数：从终点做一遍最短路
void dijkstra(){
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, T});

    memset(dist, 0x3f, sizeof dist);
    dist[T] = 0;

    while (heap.size()){
        auto t = heap.top();
        heap.pop();

        int ver = t.y;
        if (st[ver]) continue;
        st[ver] = true;
        // 从反向边开始扩展
        for (int i = rh[ver]; ~i; i = ne[i]){
            int j = e[i];
            if (dist[j] > dist[ver] + w[i]){
                dist[j] = dist[ver] + w[i];
                heap.push({dist[j], j});
            }
        }
    }
}

int astar(){   
    // 估价函数 - 真实值 - 起点
    priority_queue<PIII, vector<PIII>, greater<PIII>> heap;
    heap.push({dist[S], {0, S}});

    while (heap.size()){
        auto t = heap.top();
        heap.pop();

        int ver = t.y.y, distance = t.y.x;
        cnt[ver] ++ ;
        if (cnt[T] == K) return distance; // 出队了K次
        // 从正向图扩展
        for (int i = h[ver]; ~i; i = ne[i]){
            int j = e[i];
            // 更新所有临边
            if (cnt[j] < K)
                heap.push({distance + w[i] + dist[j], {distance + w[i], j}});
        }
    }

    return -1;
}

int main(){
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    memset(rh, -1, sizeof rh);

    for (int i = 0; i < m; i ++ ){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(h, a, b, c); //正向边
        add(rh, b, a, c); //反向边
    }
    scanf("%d%d%d", &S, &T, &K);
    // 特判一下起点等于终点
    if (S == T) K ++ ;

    dijkstra();
    printf("%d\n", astar());

    return 0;
}