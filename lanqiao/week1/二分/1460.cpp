/*
title: 蓝桥杯复习
from: acwing1460. 我在哪？
Tag: 二分 字符串哈希 USACO 2019 December Contest Bronze
Code: 数据范围只有100，我比较菜，能过的话只追求简单代码 -->STL
思路：
    题意翻译： 所有长度为ans的串两两不同。
    对于任何大于等于ans的长度k，所有长度为k的字符串，前缀ans不同，所以两两之间也不同。
    由此，题目具有二段性，可以用二分。
    如何判断：是否存在两个字符串相等。
        字符串哈希：O（N）处理，O（1）询问。 枚举N个--O(NlogN)
        STL哈希表：直接存储string，增删改查与每个串长度N相关。O(N*N*LOGN) 

*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
using namespace std;
int n;
string s;
bool check(int mid){
    unordered_set<string>hash;
    for(int i=0;i+mid-1 < s.size();i++){
        auto sub = s.substr(i,mid); //取字符串
        if(hash.count(sub)) return false;
        hash.insert(sub);
    }
    return true;
}
int main(){
    cin >> n;
    cin >> s;
    int l =1,r= n; 
    while(l <  r){
        int mid = l +r >>1;
        if(check(mid)) r= mid; // 判断长度为mid的字符串是否满足两两不同
        else l = mid+1;
    }
    cout << r << endl;
    return 0;
}