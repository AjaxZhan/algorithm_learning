/*
title: 昂贵的聘礼
from: acwing 903 
Tag: 最短路 dijkstra
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
//本题用邻接矩阵来存，建模将问题转换为从最后一个点到虚拟原点的距离
const int N = 110;
int n,m;
int w[N][N]; //表示邻接矩阵
int dist[N];
int level[N];
bool st[N];
int dijkstra(int down ,int up){
    memset(dist,0x3f,sizeof dist);
    //调用多次dijkstra
    memset(st,0,sizeof st);
    dist[0] = 0;
    for(int i=1;i<=n+1;i++){
        int t = -1;
        for(int j = 0;j <=n;j++)
            if(!st[j] && (t == -1 || dist[j] < dist[t])) t = j;
        //update
        st[t] = true;
        for(int j= 1;j<=n;j++)
            if(level[j] >=down && level[j] <= up)
                dist[j] = min(dist[j], dist[t]+w[t][j]);
    }
    return dist[1];
}
int main(){
    //朴素dijkstra处理重边
    memset(w,0x3f,sizeof w);
    //自环
    for(int i =1 ;i <=n;i++) w[i][i] = 0; 
    cin >> m >> n; //分别表示等级限制和点数量
    for(int i=1;i<=n;i++){
        int price, cnt;
        cin >> price >> level[i] >> cnt;
        //向虚拟原点连接一条边
        w[0][i] = min(price,w[0][i]);
        while(cnt --){
            int id,cost;
            cin >> id >> cost;
            w[id][i] = min(w[id][i],cost);
        }
    }
    //对等级进行处理，每次只处理支持的等级区间
    int res =0x3f3f3f3f;
    for(int i = level[1] - m; i <=level[1];i++){
        res = min(res,dijkstra(i,i+m));
    }
    cout << res << endl;
    
    return 0;
}