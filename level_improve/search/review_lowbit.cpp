/*
title: 给定一个长度为n的数列，求出数列中每个数二进制表示中1的个数
from: acwing 801
Tag: 位运算
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100010;
int a[N];
int n;
int lowbit(int x){
    return x&-x;
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++){
        int cnt = 0;
        while(a[i]){
            a[i]-=lowbit(a[i]);
            cnt++;
        }
        cout << cnt << " ";
    }

    return 0;
}