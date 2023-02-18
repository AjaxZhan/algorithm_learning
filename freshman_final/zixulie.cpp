/*
title: 期末复习
from: C语言小测
Tag: 双指针
输入两个字符串str1和str2，判断字符串str1包含字符串str2的个数，允许重叠。
*/
#include <bits/stdc++.h>
using namespace std;
string str1;
string str2;
int main(){
    int res = 0;
    int i=0;
    int j=0;
    cin >> str1 >> str2;
    while(i < str1.size()){

        while(str1[i]!=str2[j]) i++,j=0;

        while(str1[i] == str2[j]) j++,i++;
        if(j ==str2.size()) res++,i-=(str2.size()-2),j=0;
        else j=0;
    }

    cout << res << endl;

    return 0;
}