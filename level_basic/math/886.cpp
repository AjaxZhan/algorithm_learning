/*
title: 求组合数II
from: acwing 886
Tag: 快速幂 逆元 组合数
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100010;
typedef long long LL;
const int mod = 1e9+7;
int fact[N],infact[N]; //分别表示阶乘和逆元

//快速幂
int qmi(int a,int k, int p){
    int res = 1;
    while(k){
        if(k&1) res = (LL)res * a %p;
        a = (LL) a * a %p;
        k >>=1; //注意是两个>
    } 
    return res;
}
void init(){
    fact[0] = infact[0] = 1;
    for(int i=1;i<N;i++){
        fact[i] = (LL)fact[i-1] *i %mod;
        infact[i] = (LL)infact[i-1] * qmi(i,mod-2,mod) %mod;
    }  
}

int main(){
    //初始化
    init();
    int n;
    scanf("%d",&n);
    while(n--){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",(LL)fact[a] * infact[b]  % mod * infact[a-b]  % mod); //及时mod，三个数相乘可能溢出
    }
    
    
    return 0;
}