/*
title: 有依赖的背包问题
Tag: 树形dp 数组模拟链表
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 110;
int n,m,root;
// 数组模拟链表
int h[N],e[N],ne[N],idx;
int v[N],w[N];
int f[N][N];
// 建立从a指向b的边
void add(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
void dfs(int u){
    // 遍历所有子树，做分组背包
    for(int i=h[u];i!=-1;i = ne[i]){ // 物品组
        int son = e[i];
        dfs(e[i]);

        // 分组背包
        for(int j=m -v[u];j>=0;j--){ // 体积
            for(int k=0;k<=j;k++){ // 决策，枚举用了多少体积
                f[u][j] = max(f[u][j],f[u][j-k] + f[son][k]);
            }
        }
    }
    // 加入物品u
    for(int i=m;i>=v[u];i--){
        f[u][i] = f[u][i-v[u]] + w[u];
    }
    // 体积小于v[u]的物品不选
    for(int i=0;i<v[u];i++) f[u][i] = 0;
}
int main(){
    cin >> n >> m;
    // 清空邻接表
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++){
        int p;
        cin >> v[i] >> w[i] >> p;
        if(p == -1) root = i;
        else add(p,i);
    }
    dfs(root);
    cout << f[root][m] << endl;
    return 0;
}