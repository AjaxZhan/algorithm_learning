/*
title: 蓝桥杯复习
from: 799. 最长连续不重复子序列
Tag: 双指针
Code:
j的含义：j往左最远能到达什么地方？
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100010;
int a[N];
int s[N];//记录每个数出现的个数，数据如果大可以用hash
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int res = 0;
    for(int i=0,j=0;i<n;i++){ //i从右往左遍历
        s[a[i]]++; // 新增数
        while(s[a[i]]>1){ //重复的数只会是新增的数
            s[a[j]]--; 
            j++;//j往右移动
        }
        res = max(res,i-j+1);
    }
    cout << res << endl;
    return 0;
}