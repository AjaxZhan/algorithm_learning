/*
title: 1125 牛的旅行
from: acwing 1125
Tag: Floyd
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define x first
#define y second
typedef pair<double,double> PDD;
const int N = 155;
const double INF= 1e20; //double取大点
int n;
PDD q[N]; //坐标
double d[N][N]; // 最短路
double maxd[N]; // 到每个点的最大距离
char g[N][N]; //连通情况
double get_dist(PDD a, PDD b){
    double dx = a.x  - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> q[i].x >> q[i].y;
    for(int i=0;i<n;i++) cin >> g[i];

    //求出每两个点之间的距离

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(i == j) d[i][j] = 0;
            else if(g[i][j] == '1') d[i][j] = get_dist(q[i],q[j]);
            else d[i][j] = INF;

    //floyd找到每个点的最短距离

    for(int k=0;k<n;k++)
        for(int i = 0; i < n ;i ++)
            for(int j = 0;j<n;j++)
                d[i][j] = min(d[i][j] , d[i][k] + d[k][j]);
    
    double res1 = 0;
    //找出到每个点的最大距离
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            if(d[i][j] < INF / 2) //表示连通
                maxd[i] = max(maxd[i],d[i][j]);
        //res1是第一种情况，即在所有最大距离中取一个max。
        res1 = max(res1 , maxd[i]);
    }

    double res2 = INF;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(d[i][j] > INF /2)
                res2 = min(res2,maxd[i] + maxd[j] + get_dist(q[i],q[j]));
    
    printf("%.6lf\n",max(res1,res2));


    return 0;
}