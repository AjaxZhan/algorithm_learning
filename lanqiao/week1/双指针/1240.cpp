/*
title: 蓝桥杯复习
from: acwing 1240 完全二叉树的权值
Tag: 二叉树 双指针
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100010;
typedef long long LL;
LL res = -1e18; // 每个数的数据范围是-1e5 到 1e5，因为可能越界
int depth;
int n;
int a[N];

int main(){
    cin >> n;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);

    //i表示每一层的第一个数，d表示层数
    //遍历每一层
    for(int i = 1,d = 1;i<=n;i*=2,d++){ 
        LL s = 0;
        // 2^d-1 是完全二叉树每一层的节点数量
        for(int j = i; j < i+ (1 << d-1) && j <=n ;j++){ // 注意防止最后一层出现越界的情况
            s+=a[j];
        }
        if(s > res){
            res = s;
            depth = d;
        }
    }
    printf("%d\n",depth);
    return 0;
}