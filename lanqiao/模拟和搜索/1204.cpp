/*
title: 错误票据
from: acwing 1204
Tag: 模拟 排序 stringstream
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <sstream>
using namespace std;
const int N = 10010;
const int M = 1e5+10;
int cnt;
int n;
string str;
bool st[M];
int a[N];
int main(){
    cin >> cnt;
    getline(cin,str);// ！！！忽略第一行的回车

    while(cnt--){    
        getline(cin,str);
        stringstream ssin(str); // 初始化流对象
        while(ssin >> a[n]) n++;
    }

    sort(a,a+n);
    int aa = 0,bb = 0;
    for(int i=1;i<n;i++){
        //先断号后重复。
        if(a[i] == a[i-1]) bb = a[i];
        else if(a[i] - a[i-1] > 1) aa = a[i] + a[i-1] >>1;
        if(aa && bb ) break;
    }
    cout << aa << " " << bb << endl;



    return 0;
}