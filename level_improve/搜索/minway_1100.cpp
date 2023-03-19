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
const int N = 1e5+10;
int n,k;
int q[N];
int dist[N]; // 距离和是否被遍历过
int bfs(){
    int hh = 0, tt= 0;
    memset(dist,-1,sizeof dist);
    q[0] = n;
    dist[n] = 0;

    while(hh <=tt){
        int t = q[hh++];
        if(t == k) return dist[t];
        //遍历过程
        //思考边界情况
        if(t -1 >=0 && dist[t-1]==-1){
            dist[t-1] = dist[t]+1;
            q[++tt] = t-1;
        }
        if(t +1 < N && dist[t+1]==-1){
            dist[t+1] = dist[t]+1;
            q[++tt] = t+1;
        }
        if(2*t < N && dist[2*t]==-1){
            dist[2*t] = dist[t]+1;
            q[++tt] = 2*t;
        } 
    }

    //程序完整性。一定有解，所以不会执行。
    return -1;
}
int main(){
    cin >> n >> k;
    cout << bfs() << endl;
    return 0;
}