/*
title: 算法基础数论篇
from: acwing 883. 高斯消元解线性方程组
Tag: 高斯消元
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 110;
const double eps = 1e-8; //小数判断方式，0
int n;
double a[N][N];

//高斯消元，答案存放在a[i][n]中，0<=i<n
int gauss(){
    int c,r;
    for(c=0,r=0;c<n;c++){
        int t = r;
        for(int i=r;i<n;i++)    
            if(fabs(a[i][c] > fabs(a[t][c]))) t = i; // 找到绝对值最大的行
        
        if(fabs(a[t][c]) < eps) continue;

        //将绝对值最大的行交换到最顶端
        for(int i=c;i<=n;i++) swap(a[t][i],a[r][i]);
        //将当前行的首位变成1
        for(int i=n;i>=c;i--) a[r][i]/=a[r][c];
        //用当前行将下面所有行的列消成0
        for(int i = r+1;i<n;i++){
            if(fabs(a[i][c]) > eps)
                for(int j = n;j>=c;j--)
                    a[i][j]-=a[r][j]*a[i][c];
        } 
        r++;
    }
    //说明不是唯一解
    if(r < n){
        for(int i= r;i<n;i++){
            //判断增广矩阵最右边一列是否出现了非零
            if(fabs(a[i][n]) > eps) return 2 ; // 无解
        }
        return 1; // 无穷多解

    }

    //唯一解，回代
    for(int i = n-1;i>=0;i--)
        for(int j = i+1;j<n;j++)
            a[i][n] -= a[j][n] * a[i][j];
    return 0;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n+1;j++)
            scanf("%lf",&a[i][j]);
    int t = gauss();
    if(t == 2) puts("No solution");
    else if(t == 1) puts("Infinite group solutions");
    else{
        for(int i=0;i<n;i++){
            if(fabs(a[i][n]) < eps) a[i][n] = 0; // 去掉-0.00的情况
            printf("%.2lf\n",a[i][n]);
        }
    }
    return 0;
}