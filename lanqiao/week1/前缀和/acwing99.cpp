/*
title:蓝桥杯备赛复习
from:AcWing 99. 激光炸弹
Tag:前缀和 HNOI2003
Code: https://www.acwing.com/problem/content/99/
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N  = 5010;
int s[N][N];
int res;
int main(){
    int cnt,r;
    cin >> cnt >> r;
    r = min(5001,r); // 题目目标点在5000内，r太大没意义

    while(cnt--){
        int x,y,w;
        cin >> x >> y >> w;
        s[++x][++y]+=w;// 读入的时候，坐标多一位，前缀和常见防止边界的细节
    }
    //预处理前缀和
    for(int i=1;i<=5001;i++)
        for(int j=1;j<=5001;j++)
            s[i][j]+=s[i-1][j] + s[i][j-1] - s[i-1][j-1];

    //枚举变长是R的矩形,枚举右下角
    for(int i=r;i<=5001;i++)
        for(int j=r;j<=5001;j++)
            res = max(res,s[i][j] - s[i][j-r] - s[i-r][j] + s[i-r][j-r]);
        
    
    cout << res << endl;


    return 0;
}