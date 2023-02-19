/*
title: 蓝桥杯复习
from: acwing 3768 字符串删减
Tag: 双指针
Code:
双指针算法找出所有连续的x，对于每一组，res+=max(0,j-i-2)
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n;
    string s;
    cin >> n >> s;
    int res = 0;
    for(int i=0;i<n;i++){
        if(s[i]!='x') continue;
        int j = i+1;
        while( j <n && s[j] == 'x') j++;
        res += max(0,j - i-2);
        i = j-1;
    }
    cout << res << endl;
    return 0;
}