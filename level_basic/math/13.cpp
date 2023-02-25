/*
title: 算法基础之数论
from:acwing 878 线性同余方程
Tag: 扩展欧几里得 同余
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
int exgcd(int a, int b,int &x, int &y){
    if(!b){ // a 与 0的最大公约数
        x =1, y=0;
        return a;
    }
    int d = exgcd( b , a%b ,y,x);//反过来方便计算
    y -= a/b *x ;
    return d;
    //推导公式
}
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int a,b,m,x,y;
        scanf("%d%d%d",&a,&b,&m);
        int d = exgcd(a,m,x,y);
        if(b % d) puts("impossible");
        else
            printf("%d\n",(LL)x * (b/d) %m);

    }
    return 0;
}