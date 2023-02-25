/*
title: 算法基础之数论
from: acwing 876 利用快速幂求逆元
Tag: 数论
Code:
快速求 a ^b mod k
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
//求a ^ k mod p 
int qmi(int a ,int k ,int p){
    LL res = 1;
    while(k){
        //a 是不断变化的
        //如果末尾是1的话，就要加入
        if(k & 1) res = (LL) res * a % p;
        k >>= 1; //右移一位
        a = (LL) a * a %p; // 预处理的数，本质上是将a每次平方
    }
    return res;
}
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int a,p;
        scanf("%d%d",&a,&p);
        int res = qmi(a,p-2,p); 
        if(a % p == 0){
            puts("impossible");
            continue;
        }
        printf("%d\n",res);
    }
    
    return 0;
}