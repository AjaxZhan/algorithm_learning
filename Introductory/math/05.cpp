/*
title: 基础数论
from: acwing 870. 约数个数
Tag: 数学 约数 试除法 因式分解
Code: 注意输出的是这些数乘积的约数个数，因此先存也没事
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long LL;
const int MOD = 1e9+7;
int main(){
    int n;
    cin >> n;
    unordered_map<int,int>primes; // 存放质因数的底数和次数
    while(n--){
        int x;
        cin >> x;
        //分解
        for(int i=2;i<=n/i;i++){
            while(x%i == 0){
                x/=i;
                primes[i]++;
            }
        }
        if(x > 1) primes[x]++; // 处理大于根号n的质因子
    }
    LL res = 1;
    for(auto p: primes) res = res*(p.second+1)%MOD;
    cout << res << endl;
    return 0;
}