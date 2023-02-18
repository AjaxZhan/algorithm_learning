/*
title: 蓝桥杯复习
from: acwing93 组合型枚举
Tag: 递归
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 30;
int n,m;
int way[N];
void dfs(int u , int st){
    //剪枝优化:后面的数加起来还不够m
    if(u+n-st < m) return; 
    if(u == m+1){
        for(int i=1;i<=m;i++) printf("%d ",way[i]);
        puts("");
        return ;
    }
    for(int i=st;i<=n;i++){
        way[u] = i;
        dfs(u+1,i+1);
        way[u] = 0;//这句话其实会被覆盖
    }
}
int main(){
    scanf("%d%d",&n,&m);
    dfs(1,1);
    return 0;
}