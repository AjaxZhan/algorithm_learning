/*
title: 算法基础数论篇
from: acwing204 表达整数的奇怪方式
Tag: 中国剩余定理
Code: 全是数学推导，有亿点难
*/
#include <iostream>
#include <cstring>
#include <cstdio>   
#include <algorithm>
using namespace std;
typedef long long LL;

//先默写扩欧几里得算法
LL exgcd(LL a, LL b, LL&x, LL &y){
    if(!b){
        x =1, y=0;
        return a;
    }
    LL d = exgcd(b,a%b ,y,x);
    y -= a/b*x;
    return d;
}

int main(){
    int n;
    cin >> n;
    bool has_ans = true;

    LL a1,m1;
    cin  >> a1 >> m1;

    for(int i=0;i<n-1;i++){
        LL a2, m2;
        cin >> a2 >> m2;
        //每次两两合并方程

        //欧几里得算法，求出k1和k2
        LL k1, k2;
        LL d = exgcd(a1,a2,k1,k2);
        if((m2-m1) % d){
            has_ans = false;
            break;
        }
        k1 *= (m2-m1) /d;

        //下面这段推导就有点懵逼了
        LL t = a2 /d;
        k1 = (k1%t + t ) %t;
        
        m1 = a1 * k1 + m1;
        a1 = abs(a1/d*a2); //最小公倍数

    }
    if(has_ans) cout << (m1 % a1 + a1) %a1 <<endl;
    else puts("-1"); 
    
    return 0;
}