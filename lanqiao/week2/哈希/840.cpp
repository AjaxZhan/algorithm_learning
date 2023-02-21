/*
title: 蓝桥杯复习
from: acwing840 模拟散列表
Tag: 哈希
Code: 拉链法存储哈希表
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100003; // 记忆1：最佳哈希值，离1e5最近的质数
int e[N],ne[N],idx,h[N]; // 邻接表
int n;
void insert(int x){
    //hash函数
    int k = (x %N + N)%N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}
bool findhash(int x){
    int k = (x %N + N) %N;
    //遍历链表
    for(int i=h[k];i!=-1;i=ne[i])
        if(e[i] == x) return true;
    
    return false;
}
int main(){
    cin >> n;
    //记忆2：初始化
    memset(h,-1,sizeof h);

    while(n--){
        char op[2];
        int x;
        scanf("%s%d",op,&x);
        if(*op =='I') insert(x);
        else{
            if(findhash(x)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}