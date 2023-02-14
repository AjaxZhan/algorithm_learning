/*
title:蓝桥杯备赛
from:acwing 797. 二维差分
Tag:差分 模板
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1010;
int s[N][N];
int b[N][N];
void insert(int x1, int y1, int x2, int y2, int c){
    b[x1][y1]+=c;
    b[x2+1][y1]-=c;
    b[x1][y2+1]-=c;
    b[x2+1][y2+1]+=c;
}

int main(){
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&s[i][j]);
    //初始化二维差分矩阵
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            insert(i,j,i,j,s[i][j]);

    while(q--){
        int x1,y1,x2,y2,c;
        scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&c);
        insert(x1,y1,x2,y2,c);
    }

    //二维前缀和
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            b[i][j] += b[i-1][j] + b[i][j-1] -b[i-1][j-1];
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            printf("%d ",b[i][j]);
        printf("\n");
    }
    return 0;
}