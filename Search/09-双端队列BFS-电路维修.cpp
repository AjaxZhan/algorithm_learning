/*
title: 电路维修
Tag: 双端队列 BFS
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <deque>
#define x first
#define y second
using namespace std;
const int N = 510,INF=0x3f3f3f3f;
typedef pair<int,int>PII;
int n,m;
char g[N][N];
int dist[N][N];
bool st[N][N];
deque<PII>q;

// 点的坐标
int dx[4] = {-1,-1,1,1},dy[4] = {-1,1,1,-1};
// 对于某个点来说，四个方向上字符的下标偏移
int ix[4] = {-1,-1,0,0},iy[4] = {-1,0,0,-1};
// 字符偏移量
char op[] = "\\/\\/";

int bfs(){
    memset(dist, 0x3f,sizeof dist);
    memset(st, 0,sizeof st);
    q.clear();

    dist[0][0] = 0;
    q.push_front({0,0});
    
    while(q.size()){
        auto t = q.front();
        q.pop_front();
        // 可能会入队多次，特殊的dijkstra
        if(st[t.x][t.y]) continue;
        st[t.x][t.y] = true;
        for(int i=0;i<4;i++){
            int a = t.x+ dx[i],b = t.y+ dy[i];
            // 格点长度会多1
            if(a<0 || a>n || b<0 || b>m) continue;
            int char_a = t.x+ix[i],char_b = t.y+iy[i];
            int d = dist[t.x][t.y]+(g[char_a][char_b]!=op[i] ? 1: 0);
            if(d < dist[a][b]){
                dist[a][b] = d;
                // w=1，队尾
                if(g[char_a][char_b] != op[i]) q.push_back({a,b});
                // w=0，队头
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

        int res = bfs();
        if( res== INF) printf("NO SOLUTION\n");
        else printf("%d\n",res);
    }
    
    return 0;
}