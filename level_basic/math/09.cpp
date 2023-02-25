/*
title: 算法基础之数学
from: acwing 874 筛法求欧拉函数
Tag: 数论
Code:
给定一个正整数 n，求 1∼n中每个数的欧拉函数之和。
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N  = 1e6+10;
int primes[N]; 
int cnt;
int eulers[N];//存储每个数的欧拉函数
bool st[N]; // 是否为质数
void get_eulers(int n){
    eulers[1] = 1; // 筛法从2开始筛，需要初始化1

    for(int i=2;i<=n;i++){
        if(!st[i]){
            primes[cnt++] = i;
            eulers[i] = i-1;
        }
        for(int j=0;primes[j] <= n/i;j++){
            st[primes[j] * i]  =true;
            if(i % primes[j] == 0){
                eulers[primes[j] *i] = primes[j] * eulers[i];
                break;
            }
            eulers[primes[j] * i] = eulers[i] * (primes[j] - 1);
        }
    }

}
int main(){
    int n;
    cin >> n;
    //筛法获取每个数的欧拉函数
    get_eulers(n);

    LL res = 0;
    for(int i=1;i<=n;i++) res+= eulers[i];
    cout << res<< endl;
    return 0;
}   