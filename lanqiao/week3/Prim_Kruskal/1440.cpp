/*
title: 最短网络
from: acwing1140
Tag:
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 110;
int dist[N];
bool st[N];
int g[N][N];
int n;

int prim(){
    memset(dist,0x3f,sizeof dist);
    int res = 0;
    dist[1] = 0;
    for(int i=0;i<n;i++){
        int t = -1;
        
        for(int j = 1;j<=n;j++){
            if(!st[j] && (t == -1 || dist[j] < dist[t])) t= j;
        }
        res+=dist[t];
        st[t] = true;

        for(int j=1;j<=n;j++){
            dist[j] = min(dist[j],g[t][j]);
        }
        
    }
    return res;
}

int main(){
    cin >> n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin >> g[i][j];
    int t = prim();
    cout << t << endl;

    return 0;
}