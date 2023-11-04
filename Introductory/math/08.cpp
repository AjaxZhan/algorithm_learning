/*
title: 算法基础 欧拉函数
from: acwing 873 欧拉函数
Tag: 数学 欧拉函数
Code:
简介：给定N个正整数，求每个数的欧拉函数。
欧拉函数：表示1-N中于N互质的数的个数。
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 110;
int n;

int main(){
    cin >> n;
    while(n--){
        int a;
        cin >> a;
        
        //欧拉函数：N(1-1/P1)...(1-1/pk)
        int res = a;
        //分解质因数 O(SQRT(N))
        for(int i=2;i<=a/i;i++){
            if(a % i == 0){
                res  = res / i * (i-1);
                while(a % i == 0) a/=i;
            }
        }
        if(a > 1) res = res / a * (a-1);
        cout << res << endl;
    }
    return 0;
}