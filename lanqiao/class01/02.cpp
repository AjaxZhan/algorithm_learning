/*
title: 蓝桥杯复习
from: acwing94 递归实现排列型枚举
Tag: 递归
Code:
字典序最小：从小到大枚举即可。
时间复杂度：
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 12;
int st[N]; //存放数字
bool used[N];// 数字是否用过
int n;

void dfs(int u){
    if(u >n ){
        for(int i=1;i<=n;i++)
            printf("%d ",st[i]);
        puts("");
        return ;
    }
    
    for(int i=1;i<=n;i++){ // 枚举每个数
        if(!used[i]){
            st[u] = i;
            used[i] = true;
            dfs(u+1);
            used[i] = false;
        }
    }
}
int main(){
    cin >> n;
    dfs(1);
    return 0;
}