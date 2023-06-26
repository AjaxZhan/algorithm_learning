/*
title: 哈希表--模拟散列表
from: acwing 841 模拟散列表
Tag: 哈希表
Code: 开放寻址法
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 200003,null = 0x3f3f3f3f; // 经验值是开数据范围的两倍
int h[N];
int findhash(int x){ // 存在返回位置，不存在返回应该存储的位置
    int k = (x %N + N) %N;
    while(h[k] !=null && h[k]!=x){
        k++;
        if(k==N) k=0;
    }
    return k;
}
int main(){
    int n;
    scanf("%d",&n);
    //初始化邻接表
    memset(h, 0x3f , sizeof h);
    while(n--){
        char op[2];
        int x;
        scanf("%s %d",op,&x);
        int k = findhash(x);
        if(*op == 'I') h[k] = x;
        else{
            if(h[k]!= null) puts("Yes");
            else puts("No");
        }

    }
    return 0;
}