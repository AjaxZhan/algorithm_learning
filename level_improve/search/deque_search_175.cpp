/*
title: 电路维修
from: acwing 175
Tag: 双端队列BFS
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;
const int N = 510;
const int INF = 0x3f3f3f3f;
typedef pair<int,int>PII;
#define x first
#define y second
int n,m;
char g[N][N];
int dist[N][N];
bool st[N][N];
int bfs(){
    //多组数据必备初始化
    memset(dist,0x3f,sizeof dist);
    memset(st,0,sizeof st);
    dist[0][0] = 0;
    deque<PII>q;
    q.push_back({0,0});
    
    //枚举偏移量
    char cs[] = "\\/\\/";
    int dx[4] = {-1,-1,1,1},dy[4] = {-1,1,1,-1};
    int ix[4] = {-1,-1,0,0},iy[4] = {-1,0,0,-1};

    while(q.size()){
        PII t = q.front();
        q.pop_front();
        if(st[t.x][t.y]) continue;
        //取出对头的时候判断，当成特殊的dijkstra算法
        //一个点可能会多次入队，因为
        st[t.x][t.y]  = true;
        for(int i=0;i<4;i++){
            int a = t.x+dx[i];
            int b = t.y+dy[i];
            if(a < 0 || a>n || b<0 || b>m) continue;
            int ca = t.x+ix[i],cb = t.y+iy[i];
            int d = dist[t.x][t.y]+(g[ca][cb]!=cs[i]);
            if(d < dist[a][b]){
                dist[a][b] = d;
                if(g[ca][cb] != cs[i]) q.push_back({a,b});
                else q.push_front({a,b});
            }
        }
    }
    return dist[n][m];
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) scanf("%s",g[i]);
        int t = bfs();
        if(t == INF) puts("NO SOLUTION");
        else printf("%d\n",t);
    }
    
    return 0;
}