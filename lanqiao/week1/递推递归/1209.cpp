/*
title: 蓝桥杯备赛
from: acwing1209 带分数
Tag: 递归 搜索 剪枝 蓝桥杯真题
Code:
思路：
    先枚举a，对于每一个枚举的a再去枚举c，对于每一个枚举的c，最后判断B是否满足。
    注意：每一个位数都不能为0；

*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 20;
int n;
bool st[N];//判重数组
bool backup[N];
int ans;

bool check(int a, int c){
    int b = n*c - a*c;
    if(!a || !b || !c) return false; // 保证没有0
    //先copy一个数组
    memcpy(backup, st,sizeof st);
    //判断B的数是否出现过，出现过就gg
    while(b){
        int x = b%10;
        b/=10;
        if(!x || backup[x]) return false;
        backup[x] = true;
    }
    //判断是否每个数都用到了，没用到gg
    for(int i=1;i<=9;i++)
        if(!backup[i]) return false;
    
    return true;
}

void dfs_c(int u ,int a, int c){
    if(u == n) return;
    if(check(a,c)) ans++;
    for(int i=1;i<=9;i++)
        if(!st[i]){
            st[i] =true;
            dfs_c(u+1,a,c*10+i);
            st[i] = false;
        }
}

void dfs_a(int u , int a){ // 当前枚举的位数 以及 a是多少
    if(a>=n) return; // 显然，a不能大于n
    if(a>0) dfs_c(u,a,0); // 加一个判断，每一位不能为0。
    for(int i=1;i<=9;i++)
        if(!st[i]){
            st[i] = true;
            dfs_a(u+1,a*10+i);
            st[i] = false;
        }
}

int main(){
    cin >> n;   
    dfs_a(0,0);
    return 0;
}