/*
title: 蓝桥杯复习
from: 831 字符串匹配
Tag: KMP
Code: KMP匹配
核心思路：匹配不成功就退到ne[j]
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 10010, M = 100010;
int n,m;
char s[M],p[N]; // 模式串和匹配串
int ne[N]; //ne数组，ne[i]=j 表示长度为j的，以i结尾的后缀 和以从1开始的前缀相
int main(){
    //下标从0开始
    cin >> n >> p+1 >> m >> s+1 ;
    
    //求next数组
    for(int i=2,j=0;i<=n;i++){ // 从2开始，ne[1]必定为0
        while(j && p[i]!=p[j+1]) j = ne[j]; // 如果匹配不成功，则退到nej的位置
        if(p[i] == p[j+1]) j++; //匹配成功，往前继续走
        ne[i] = j; // 记录ne
    }

    //KMP匹配

    for(int i=1,j=0;i<=m;i++){
        while(j && s[i]!=p[j+1]) j = ne[j];
        if(s[i] == p[j+1]) j++;
        if(j == n){
            //匹配成功
            printf("%d",i-n+1 - 1); //下标从0开始
            j = ne[j]; // 匹配成功后，记得回到ne[j]
        }
    }
    return 0;
}