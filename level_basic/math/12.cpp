/*
title: 算法基础之数论
from:acwing 877 扩展欧几里得算法
Tag: 扩展欧几里得 裴蜀定理
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
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
        int a,b,x,y;
        scanf("%d%d",&a,&b);
        exgcd(a,b,x,y);
        printf("%d %d\n",x,y);

    }
    return 0;
}