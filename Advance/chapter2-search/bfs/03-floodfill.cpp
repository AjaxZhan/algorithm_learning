/*
title: 山峰和山谷
Tag: FloodFill BFS
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define x first
#define y second
typedef pair<int,int> PII;
const int N = 1010 , M = N*N;
int n;
int h[N][N];
bool st[N][N];
PII q[M];
/**
 * @brief Flood Fill
 * 
 * @param sx 起点x
 * @param sy 起点y
 * @param high 引用，是否有比其高
 * @param lower 引用，是否有比其矮 
 */
void bfs(int sx, int sy, bool &high, bool & lower){
    int hh =0, tt=0;
    q[0] = {sx,sy};
    st[sx][sy] = true;

    while(hh <=tt){
        auto t = q[hh++];
        for(int i=t.x-1;i<=t.x+1;i++)
            for(int j= t.y-1;j<=t.y+1;j++)
            {
                if(i == t.x && j == t.y) continue;
                if(i <0 || i>=n || j<0 || j>=n) continue;
                if(h[i][j] !=h[t.x][t.y]) //判断是否有比他高
                {
                    if(h[i][j] > h[t.x][t.y]) high = true;
                    else lower = true;
                }
                //没遍历过，入队
                else if(!st[i][j])
                {
                    q[++tt] = {i,j};
                    st[i][j] = true;
                }
            }
    }
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&h[i][j]);
    int peak = 0, valley = 0; // 山峰和山谷
    //Flood Fill
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(!st[i][j])
            {
                bool high = false , lower= false; //周围是否有比起高/矮
                bfs(i,j,high,lower);

                if(!high) peak++; //没有比其高
                if(!lower) valley++; // 没有比其矮，不能else
            }
    printf("%d %d\n",peak,valley);
    return 0;
}