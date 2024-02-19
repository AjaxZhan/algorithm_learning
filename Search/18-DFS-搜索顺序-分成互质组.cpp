/*
title: 分成互质组
Tag: DFS 判断质数 欧几里得算法
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 10;
int n;
int p[N]; // 数据
int group[N][N]; // 组数
int ans = N;
bool st[N];
// 欧几里得算法
int gcd(int a, int b){
    return b ? gcd(b,a%b) : a;
}
// 判断组内所有元素都和i互质
bool check(int g[], int gi, int i){
    for(int j=0;j<gi;j++){
        if(gcd(p[g[j]],p[i]) > 1) return false;
    }
    return true;
}
/**
 * u：正在搜索的组数。
 * g_idx：组内元素个数。
 * total：元素视角，已经搜了多少元素
 * start：正在搜索的元素下标
 */
void dfs(int u,int g_idx, int total,int start){ // 
    if(u>=ans) return ; // 不是最优解，剪枝
    if(total == n) { // 搜完所有元素，更新答案
        ans = u;
    }
    bool flag = true; // 是否新开一个组
    for(int i=start;i<n;i++){
        if(!st[i] && check(group[u],g_idx,i)){
            st[i] = true;
            group[u][g_idx] = i;
            dfs(u,g_idx+1,total+1,i+1);
            st[i] = false;

            flag = false;
        }
    }
    // 新开一个组
    if(flag) dfs(u+1,0,total,0);
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> p[i];

    dfs(1,0,0,0); // 第一组 组内元素 搜了多少 从哪里开始搜

    cout << ans << endl;

    return 0;
}