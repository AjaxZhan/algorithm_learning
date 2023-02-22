/*
title: 蓝桥杯复习
from: acwing841 字符串哈希
Tag: 哈希 字符串哈希
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100010,P=131; // P经验值
typedef unsigned long long ULL; //记忆1：用ULL代替取模
int n,m;
char str[N];
ULL h[N],p[N];  //h[i]表示前i个字母的哈希
// 记忆2：h存哈希，p存预处理的p次方

//获取哈希值
ULL gethash(int l , int r){
    return h[r] - h[l-1] *p[r-l+1];
}
int main(){
    scanf("%d%d",&n,&m);
    scanf("%s",str+1); // 从1开始
    p[0] = 1;

    //预处理幂和前缀哈希
    for(int i=1;i<=n;i++){
        p[i] = p[i-1]*P; // 预处理P的多少次幂
        //秦九韶算法，先左移一位再加上个位
        h[i] = h[i-1]*P + str[i];
        /*
        str = ABCD
        h[1] = s[1];
        h[2] = s[1]*P + s[2]
        h[3] = (s[1]*p^2 + s[2]*p) + s[3]
        */ 
    }
    while(m--){
        int l1,r1,l2,r2;
        scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
        if(gethash(l1,r1) == gethash(l2,r2)) puts("Yes");
        else puts("No");
    }
    return 0;
}