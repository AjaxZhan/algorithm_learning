/*
title: 蓝桥杯复习
from: acwing800 数组元素目标和
Tag: 双指针
Code:
基本思路：利用单调性，i从左枚举，j从右枚举，当大于x就j--
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N =100010;
int n,m,x;
int a[N],b[N];
int main(){
    cin >> n >> m >>x;
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<m;i++) scanf("%d",&b[i]);
    for(int i=0,j=m-1;i<n;i++){
        while(j >= 0 && a[i] + b[j] >x) j--;
        if(a[i] + b[j] ==x){
            cout << i <<" " << j << endl;
            break;
        }
    }
    return 0;
}