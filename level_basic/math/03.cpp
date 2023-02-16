/*
title: 基础数论
from: acwing 868. 筛质数
Tag: 数学 质数 筛法求质数
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100010;
int prime[N]; // 存质数
int cnt; // 存质数个数
bool st[N]; // 是否是质数
//朴素筛
void get_prime1(int n){
    for(int i=2;i<=n/i;i++){
        if(!st[i]) prime[cnt++] = i;
        for(int j = i*i;j<=n;j+=i) st[j] = true; //筛掉倍数
    }
}
//埃式筛:将筛倍数放到判断内即可
void get_prime2(int n){
    for(int i=2;i<=n/i;i++){
        if(!st[i]){
            prime[cnt++] = i;
            for(int j = i*i;j<=n;j+=i) st[j] = true; //筛掉倍数
        }
    }
}
//线性筛：n只会被最小质因子筛掉 

void get_prime3(int n){
    for(int i=2;i<=n;i++){
        if(!st[i]) prime[cnt++] = i;
        for(int j=0;prime[j] <= n/i;j++){ // 从小到大，枚举质数
        /*
        如果 i% pj==0
            primes[j]一定是i的最小质因子，因为是从小到大枚举的所有质数。
            说明pj一定是pj *i 的最小质因子
        如果 i%pj!=0
            说明pj一定小于i的所有质因子。
            pj也一定是pj*i的最小质因子。*/
            st[prime[j]*i] = true;
            if(i %prime[j] == 0) break;
        }
    }
}


int main(){
    int n;
    cin >> n;
    get_prime1(n);
    cout << cnt << endl;
    return 0;
}