/*
title: 蓝桥杯备赛
from: acwing92 递归实现指数型枚举
Tag: 递归
Code: 思路：依次考虑选和不选两种状态，在到达叶节点的时候输出方案
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 20;
int n;
int st[N]; // 存储每个数字的状态，0表示未考虑，1表示选择，2表示不选择
void dfs(int u){
    //判断是否到达边界
    if(u > n){
        for(int i=1;i<=n;i++)
            if(st[i] == 1) cout << i << " ";
        cout << endl;
        return ;
    }

    //不选择
    st[u] = 2;
    dfs(u+1);
    st[u] = 0; //回溯

    //选择
    st[u] = 1;
    dfs(u+1);
    st[u] = 0;
    

}
int main(){
    cin >> n;
    dfs(1);
    return 0;
}