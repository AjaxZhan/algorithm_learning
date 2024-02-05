/*
title: 导弹升级
Tag: LIS dfs求最小步数
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 55;
int n;
int q[N]; // 导弹序列
int up[N],down[N]; // 保存上升子序列和下降子序列的最后一个序列的长度
int ans;

void dfs(int cur , int cnt_up, int cnt_down){
    // 求解的是最小值
    if(cnt_up + cnt_down >= ans) return;
    // 搜到叶子节点
    if(cur == n){
        ans = cnt_up + cnt_down;
        return ;
    }
    // 分支1：将当前数放到上升子序列中
    int k = 0;
    while(k < cnt_up && up[k] >= q[cur]) k++;
    int tmp = up[k];
    up[k] = q[cur];
    if(k < cnt_up){
        // 不需要插入开辟新序列
        dfs(cur+1,cnt_up,cnt_down);
    }else{
        dfs(cur+1,cnt_up+1,cnt_down);
    }
    // 回溯
    up[k] = tmp;
    // 分支2：将当前数放到下降子序列中
    k = 0;
    while(k < cnt_down && down[k] <= q[cur]) k++;
    tmp = down[k];
    down[k] = q[cur];
    if(k < cnt_down){
        // 不需要插入开辟新序列
        dfs(cur+1,cnt_up,cnt_down);
    }else{
        dfs(cur+1,cnt_up,cnt_down+1);
    }
    // 回溯
    down[k] = tmp;
}

int main(){
    while(cin >> n ,n ){
        for(int i=0;i<n;i++) cin>> q[i];
        ans = n;
        dfs(0,0,0);
        cout << ans << endl;
    }
    return 0;
}