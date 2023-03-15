/*
title: 导弹防御系统
from: acwing 187
Tag: LIS DFS 贪心
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 55;
int n;
int q[N];
int up[N],down[N]; // 记录的是上升子序列和下降子序列的个数
int ans; //全局答案，最小值
void dfs(int u , int su , int sd){
    //表示当前的数，上升子序列个数，下降子序列个数
    if(su + sd >= ans) return;
    if(u == n){
        ans = su + sd; //枚举到了最后一个数。
        return;
    }
    //情况1：当前的数放到上升子序列中
    int k = 0;
    while(k < su && up[k]>=q[u]) k++;
    int t = up[k];//备份
    up[k] = q[u];
    if(k < su) dfs(u+1,su,sd); //不需要创建一个新的系统
    else dfs(u+1,su+1,sd);
    up[k] = t; //恢复现场

    //情况2：当前的数字放到下降子序列中
    k = 0;
    while(k < sd && down[k]<=q[u]) k++;
    t= down[k];
    down[k] = q[u];
    if(k < sd) dfs(u+1,su,sd);
    else dfs(u+1,su,sd+1);
    down[k] = t;
}
int main(){
    //多组测试数据
    while(cin >> n, n){
        for(int i=0;i<n;i++) cin >> q[i];
        ans = n;
        dfs(0,0,0);
        cout << ans << endl;
    }
    
    return 0;
}