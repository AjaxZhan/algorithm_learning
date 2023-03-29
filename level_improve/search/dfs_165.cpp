/*
title: 小猫爬山
from: acwing 165
Tag: DFS剪枝
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 20;
int n,m;
int sum[N];
int c[N];
int ans = N;
void dfs(int u, int k){
    //最优性剪枝
    if(k>=ans) return;
    if(u == n){
        ans = k;
        return ;
    }
    
    for(int i=0;i<k;i++){
        //可行性剪枝
        if(sum[i]+c[u] <= m){
            sum[i]+=c[u];
            dfs(u+1,k);
            sum[i]-=c[u];
        }
    }
    //新开一辆车
    sum[k] = c[u];
    dfs(u+1,k+1);
    sum[k] = 0; // 恢复现场

}
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> c[i];
    //优化搜索顺序剪枝
    sort(c,c+n);
    reverse(c,c+n);

    dfs(0,0);
    cout << ans << endl;
    return 0;
}