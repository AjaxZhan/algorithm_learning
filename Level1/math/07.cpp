/*
title: 基础数论
from: acwing 871. 约数之和
Tag: 数学 约数 试除法 因式分解
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long LL;
const int MOD  = 1e9+7;
int main(){
    int n;
    cin >> n;
    unordered_map<int,int>primes;
    while(n--){
        int x;
        cin  >> x;
        for(int i=2;i<=n/i;i++){
            while(x %i == 0){
                x/=i;
                primes[i]++;
            }
        }
        if(x > 1) primes[x]++;
    } 
    LL res = 1;
    for(auto p : primes){
        LL a = p.first;// 底数
        LL b = p.second; // 指数
        LL t = 1; //每一项的结果
        while(b--)
            t = (t * a + 1) %MOD;
            //1*2+1 = 3;  3*2+1 = 7; 7*2+1 = 15; 模拟一下，本质上是等比数列的求和公式Sn = q*Sn-1 +1;
        res = res *t %MOD;
    }
    cout << res << endl;
    return 0;
}