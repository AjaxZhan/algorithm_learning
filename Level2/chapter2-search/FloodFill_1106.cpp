/*
title: 山峰和山谷
from: acwing 1106
Tag: BFS FloodFill
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1010 ,M = N*N;
#define x first
#define y second
typedef pair<int,int> PII;
int n;
int h[N][N];
bool st[N][N];
PII q[M];

void bfs(int sx, int sy , bool& has_higher, bool& has_lower){
    int hh = 0,tt = 0;
    q[0] = {sx,sy};
    st[sx][sy] = true;

    while(hh<=tt){
        PII t = q[hh++];
        
        //枚举四个方向
        for(int i=t.x-1;i<=t.x+1;i++){
            for(int j= t.y-1;j<=t.y+1;j++){
                if(i == t.x && j == t.y) continue; //八连通遍历别忘记扣掉
                if(i <0 || i>=n || j < 0 || j>=n) continue;
                //判断与山脉接壤的块的性质
                if(h[i][j]!=h[t.x][t.y]){
                    if(h[i][j] < h[t.x][t.y]) has_lower = true;
                    else has_higher = true;
                }else{
                    if(!st[i][j]){
                        q[++tt] = {i,j}; // ++tt
                        st[i][j] = true;
                    } 
                }
            }
        }
    }
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&h[i][j]);
    
    //记录山峰和山谷的个数
    int peak = 0, valley = 0;
    //FloodFill 遍历每个点
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(!st[i][j]){
                bool has_higher = false, has_lower = false;
                bfs(i,j,has_higher,has_lower);
                if(!has_higher) peak++;
                if(!has_lower) valley++;
            }
            //注意这里不能用else，因为可能又是山峰又是山谷
        }
    printf("%d %d",peak, valley);
    return 0;
}