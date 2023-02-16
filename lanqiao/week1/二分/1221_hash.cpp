/*
title: 蓝桥杯备赛
from: acwing 1221. 四平方和
Tag: 二分 哈希 蓝桥真题
Code: hash解法
思路：
最暴力做法：枚举三个数。
    但是，分析时间，由于N<=5*10^6 那么每个数必然 <= 2.232*1000 = 2232 因此最多枚举两个数，否则超时。
    因此只能考虑空间换时间：先枚举C和D，存储C^2+D^2 ，然后枚举A和B的时候再查询即可。
    查询：哈希表或者二分。
题目要字典序最小，因此要对C^2+D^2排序-- 结构体排序
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#define x first
#define y second
typedef pair<int,int> PII;
using namespace std;
unordered_map<int,PII>S;
const int N = 2500010;
//利用结构体排序特点，找到字典序最小解
struct Sum{
    int s,c,d;
    bool operator<(const Sum &t)const{
        if(this->s!=t.s) return this->s < t.s;
        if(this->c!=t.c) return this->c < t.c;
        return this->d < t.d;
    }
}sum[N];
int n,m;
int main(){
    cin >> n;
    for(int c =0;c<=n/c;c++)
        for(int d = c; c*c+d*d<=n;d++){
            //按照字典序枚举，因此存储第一个即可
            int t = c*c +d *d;
            if(S.count(t) == 0) S[t] = {c,d};
        }
    for(int a =0;a*a<=n;a++)
        for(int b=a;a*a+b*b<=n;b++){
            int t = n -a*a - b*b;
            if(S.count(t)){
                printf("%d %d %d %d",a,b,S[t].x,S[t].y);
                return 0;
            }
        }
    return 0;
}