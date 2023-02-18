/*
title: 428. 数列
from: acwing 428
Tag: 二进制 映射 递推
Code: NOIP2006普及组
N最大是1000，因此枚举到9位即可。
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int power(int k, int i){
    int res = 1;
    while(i--){
        res*=k;
    }
    return res;
}

int main(){
    int k,n;
    cin >> k >>n;
    //将序列中的每一个数映射到一个唯一的二进制数
    //可以证明：当二进制数 >的，则原数也大。证明：等比数列
    //因此，第n个数一定对应一个二进制数，只需要枚举其为1的位，反射回去
    int res = 0;
    for(int i=0;i<10;i++)
        if(n >>i &1) res+=power(k,i);
    
    cout << res << endl;
    return 0;
}