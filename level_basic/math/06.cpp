/*
title: 基础数论
from: acwing872. 最大公约数 gcd = greatest common divisor
Tag:数学 约数 最大公约数 欧几里得算法
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int gcd(int a, int b){
    return b ? gcd(b,a%b) : a;
    /*
    3 6 ==> 6 3 ==> 3 0 ==> 3
    */
}
int main(){
    int n;
    cin >> n;
    while(n--){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",gcd(a,b));
    }
    return 0;
}