/*
title: 哈希表--模拟散列表
from: acwing 841 模拟散列表
Tag: 哈希表
Code: 拉链法存储哈希表
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100003; // 最佳哈希值，离1e5最近的质数
int h[N],ne[N],e[N],idx;
void insert(int x){
    int k = (x %N +N)%N; // 哈希。并且保证正数
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}
bool findhash(int x){
    int k = (x%N +N) %N;
    for(int i=h[k];i!=-1;i=ne[i]){
        if(e[i] == x) return true;
    }
    return false;
}
int main(){
    int n;
    scanf("%d",&n);
    //初始化邻接表
    memset(h, -1 , sizeof h);
    while(n--){
        char op[2];
        int x;
        scanf("%s %d",op,&x);
        if(*op == 'I') insert(x);
        else{
            if(findhash(x)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }

    }
    return 0;
}