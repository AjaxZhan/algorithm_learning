/*
title: C语言期末复习
from: C语言小测
Tag: 模拟
Code: 生成一个元素从1开始螺旋递增的矩阵（1<=n<=15）
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 16;
int a[N][N];
int cnt;
int main(){
    int n;
    cin >> n;
    int dest = n*n;
    int r_st=0,r_ed=n-1,c_st=0,c_ed=n-1;
    while(cnt <dest){
        for(int i=c_st;i<=c_ed;i++)
            a[r_st][i] = ++cnt;
        for(int i = r_st+1;i<=r_ed;i++)
            a[i][c_ed] = ++cnt;
        for(int i = c_ed-1;i>=c_st;i--)
            a[r_ed][i] = ++cnt;
        for(int i= r_ed-1;i>=r_st+1;i--)
            a[i][c_st] = ++cnt;
        r_st++;
        c_st++;
        r_ed--;
        c_ed--;
    }
    for(int i=0;i<n;i++){   
        for(int j=0;j<n;j++)
            printf("%-5d",a[i][j]); // 左对齐
        cout << endl;
    }
    return 0;
}