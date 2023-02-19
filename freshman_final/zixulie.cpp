/*
title: 期末复习
from: C语言小测
Tag: 双指针 KMP
输入两个字符串str1和str2，判断字符串str1包含字符串str2的个数，允许重叠。
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1000010;
string s,p;
int ne[N];
int cnt;
int main(){
    // getline(cin,s); 有时候需要读空格， 注意getline会读取空格
    // getline(cin,p); 
    cin >> s >> p;
    int n= p.size();
    int m = s.size();
    //有点问题，需要在首部插入一个数，保证KMP从1开始，用insert！
    s.insert(0,1,'0');
    p.insert(0,1,'0');
    //next数组
    for(int i=2,j=0;i<=n;i++){
        while(j && p[i]!=p[j+1]) j =ne[j];
        if(p[i] == p[j+1] ) j++;
        ne[i] = j;
    }

    //KMP匹配
    for(int i=1,j=0;i<=m;i++){
        while(j && s[i]!= p[j+1]) j= ne[j];
        if(s[i] == p[j+1]) j++;
        if(j==n){
            cnt++;
            j  = ne[j];
        }
    } 

    cout << cnt << endl;
    return 0;
}