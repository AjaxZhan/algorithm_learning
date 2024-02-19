/*
title: 抓住那头牛
Tag: BFS
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5+10;
int n,k;
int q[N];
int dist[N];
int main(){
    cin >> n >> k;
    memset(dist,-1,sizeof dist);
    int hh = 0, tt = 0;
    q[0] = n;
    dist[n] = 0;
    while(hh <= tt){
        int t = q[hh++];
        if(t == k) break;
        if(t-1 >=0 && dist[t-1] == -1){
            dist[t-1] = dist[t]+1;
            q[++tt] = t-1;
        }
        if(t+1<N && dist[t+1] == -1 ){
            dist[t+1] = dist[t] + 1;
            q[++tt] = t+1;
        }
        if(2*t < N && dist[2*t] == -1){
            dist[2*t] = dist[t] + 1;
            q[++tt] = 2*t;
        }
    }

    printf("%d",dist[k]);

    return 0;
}