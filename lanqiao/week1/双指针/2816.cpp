/*
title: 蓝桥杯复习
from: acwing2816判断子序列
Tag: 双指针 
Code:
注意是判断子序列不是子串
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100010;
int a[N],b[N];
int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];
    int i=0;
    for(int j=0;j<m;j++){
        if( i<n && a[i] == b[j]) i++;
    }
    if(i ==n) puts("Yes");
    else puts("No");

    return 0;
}