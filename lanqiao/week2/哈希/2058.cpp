/*
title: 蓝桥杯复习
from: acwing 2058. 笨拙的手指
Tag: 哈希 二进制 暴力
Code:
题意：找到二进制和三进制中，只有一位和给定的数不同的数。
思路：枚举只有和二进制一位不同的数，为集合A；枚举只有和三进制一位不同的数，为集合B
题目给定有唯一解：只需要判断两个集合的交集。
枚举二进制一位不同：对每一位异或1，转为十进制后存入哈希表。
枚举三进制一位不同：每次有两种选择，也是转为十进制后存入哈希表。
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
using namespace std;

//将b进制转换为十进制
int get(string s, int b){
    int res = 0;
    for(auto c :s)
        res = res*b + c - '0';
    
    return res;
}
int main(){
    string a,b;
    cin >> a >> b;
    unordered_set<int>h; // 存放枚举后的数转换为十进制

    //枚举二进制一位不同的数
    for(auto& c :a){
        c ^=1;
        h.insert(get(a,2));
        c ^=1;//复原
    }
    //枚举三进制一位不同的数
    for(auto& c : b){
        char tmp = c; // 保存，方便复原
        for(int i=0;i<3;i++){ 
            if(tmp != i+'0'){ // 不同 --》改变后哈希
                c = i + '0';
                int x = get(b,3);
                if(h.count(x)){ // 判断是否已经满足
                    cout << x << endl;
                    return 0;
                }
            }
        }
        c= tmp; // 枚举每一位后要复原
    }
    return 0;
}