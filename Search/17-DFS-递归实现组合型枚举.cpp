/*
title: 递归实现组合型枚举
Tag: DFS
Description: 从1-n选m个，输出所有可能的方案。字典序。
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m;
const int N = 30;
int way[N];
void dfs(int u , int start){
    if(u == m + 1){
        for(int i=1;i<=m;i++) printf("%d ",way[i]);
        printf("\n");
        return;
    }
    // 枚举
    for(int i=start;i<=n;i++){
        way[u] = i;
        dfs(u+1,i+1);
        way[u] = 0;
    }

}
int main(){
    scanf("%d%d",&n,&m);
    dfs(1,1);
    return 0;
}