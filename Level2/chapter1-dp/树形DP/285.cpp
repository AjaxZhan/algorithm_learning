/*
title: 没有上司的舞会
from: acwing 285
Tag: 树形DP
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 6060;
int n;
int f[N][2];
//存储是否存在父节点
bool st[N];
int w[N];
int h[N],ne[N],e[N],idx;
void add(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dfs(int u){
    //选择/或者不选择
    f[u][0] = 0;
    f[u][1] = w[u];

    for(int i = h[u];~i;i=ne[i]){
        int j = e[i];
        dfs(j);
        f[u][0] += max(f[j][0],f[j][1]);
        f[u][1] +=f[j][0];
    }
}


int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    //初始化邻接表
    memset(h,-1,sizeof h);

    for(int i=0;i<n-1;i++){
        int a, b;
        scanf("%d%d",&a,&b);
        add(b,a);
        st[a] = true;
    }        
    //找到父节点
    int root = 1;
    while(st[root]) root++;
    dfs(root);
    printf("%d\n",max(f[root][0],f[root][1]));
    return 0;
}