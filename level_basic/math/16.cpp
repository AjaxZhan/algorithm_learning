/*
title: 算法基础之数论篇
from: acwing 891 Nim游戏
Tag: 博弈论 Nim游戏
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int n;
    int res = 0;
    scanf("%d",&n);
    while(n--){
        int x;
        scanf("%d",&x);
        res ^=x;
    }
    if(!res) puts("No");
    else puts("Yes");
    return 0;
}