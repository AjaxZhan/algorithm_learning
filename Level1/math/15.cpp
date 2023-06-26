/*
title: 算法基础之数论
from: acwing 890
Tag: 容斥原理
Code:给定一个整数n，和m个不同的质数。
求1到n中，能被这m个数至少一个整除的整数有多少个。
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 20;
int n,m;
int p[N];
int main(){
    cin >> n >> m;  
    for(int i=0;i<m;i++) cin >> p[i]; // 读入m个质数

    int res = 0;

    for(int i=1;i< 1 << m; i++){ // 1 ~ 2^m

        int t = 1; // 选中集合对应的质数乘积
        
        int s = 0; // 选中的集合数量，用于判断是奇数个还是偶数个

        for(int j=0;j<m;j++){
            if(i >> j & 1){

                if((LL) t*p[j]>n){ //超过说明不用算。
                    t = -1;
                    break;
                }
                s++; //这位是1，说明选中了这个集合

                t *= p[j]; // 
            }
        }
        if( t == -1) continue; // 这种状态不用算
        
        if(s %2 ) res+= n/t;  //奇数个集合
        else res -= n/t; // 偶数个集合

    }
    cout << res << endl;

    return 0;
}