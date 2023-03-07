/*
title: 道路与航线
from: acwing 342
Tag: dijkstra 拓扑排序 最短路
Code: 属于综合题，偶尔写这种题可以很好训练模板和思维。
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define x first
#define y second
using namespace std;
typedef pair<int,int>PII;
const int INF = 0x3f3f3f3f;
const int N = 25010 , M = 150010; // 无向边 + 有向边

int n,mr,mp,S; // 道路，航线，起点
int h[N],e[M],ne[M],idx,w[M];
int id[N];//连通块编号
vector<int>block[N]; //存储连通块内部的点
int dist[N]; //dijkstra
bool st[N];
int bcnt; //连通块编号
int din[N];//入度
queue<int>q;

void add(int a, int b , int c){
    w[idx] = c;
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dfs(int u , int bid){
    id[u] = bid;
    block[bid].push_back(u);

    for(int i=h[u];i!=-1;i=ne[i]){
        int j = e[i];
        if(!id[j]) dfs(j,bid); 
    }
}

void dijkstra(int bid){
    //连通块内部做dijkstra
    priority_queue<PII,vector<PII>,greater<PII>>heap;
    
    for(auto u : block[bid]){
        heap.push({dist[u],u});
    }
    while(heap.size()){
        auto t = heap.top();
        heap.pop();

        int ver = t.y, distance = t.x;
        if(st[ver]) continue;
        st[ver] = true;
        for(int i = h[ver];~i;i=ne[i]){
            int j = e[i];
            if(id[j] != id[ver] && -- din[id[j]] == 0) q.push(id[j]);
            if(dist[j] > distance  + w[i]){
                dist[j] = distance  + w[i];
                if(id[j] == id[ver]) heap.push({dist[j],j});
            }
        }
    }
}

void topsort(){
    memset(dist,0x3f,sizeof dist);
    dist[S] = 0; //起点

    for(int i=1;i<=bcnt;i++){
        if(!din[i]) q.push(i);
    }
    while(q.size()){
        int t = q.front();q.pop();
        dijkstra(t);
    }
}



int main(){
    scanf("%d%d%d%d",&n,&mr,&mp,&S);
    memset(h,-1,sizeof h);
    //道路
    while(mr--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
        add(b,a,c);
    }
    //DFS连通块
    for(int i=1;i<=n;i++){
        if(!id[i]){
            bcnt++;
            dfs(i, bcnt);
        }
    }
    //航线
    while(mp--){
        int a, b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
        din[id[b]]++;
    }
    topsort();

    for(int i=1;i<=n;i++)
        if(dist[i] > INF/2) cout << "NO PATH" << endl;
        else cout << dist[i] << endl;
    

    return 0;
}