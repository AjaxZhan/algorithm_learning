/*
title: 矩阵距离
from: acwing 173
Tag: 多源BFS
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int,int> PII;
#define x first
#define y second
const int N = 1010 , M = N*N;
PII q[M];
int dist[N][N];
int n,m;
char g[N][N];
int dx[4] = {-1,0,1,0},dy[4] = {0,1,0,-1};
void bfs(){
    memset(dist,-1,sizeof dist);
    int hh=0,tt=0;
    //找到所有矩阵为1的点，入队
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(g[i][j] == '1'){
                q[++tt] = {i,j};
                dist[i][j] = 0;
            }
    while(hh <=tt){
        PII t = q[hh++];
        for(int i=0;i<4;i++){
            int a = t.x+dx[i], b = t.y+dy[i];
            
            if(a <0 || a>=n || b <0 || b>=m) continue;
            if(dist[a][b] != -1) continue;

            dist[a][b] = dist[t.x][t.y]+1;
            q[++tt] = {a,b};
        }
    }
    

}
int main(){
    cin >> n >> m;
    //坑：输入是中间没空格的，要用字符串来读
    for(int i=0;i<n;i++)
        scanf("%s",g[i]); // 这里不用加取地址

    bfs();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            printf("%d ",dist[i][j]);
        cout << endl;
    }

    return 0;
}