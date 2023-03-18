/*
title: 移动距离
from: acwing 1219
Tag: 模拟
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int w,m,n;
int main(){
    cin >>w >> m >> n;
    //忘记先对坐标进行处理了
    m--,n--;
    int row1 = m / w , row2 = n/w;
    int col1 = 0 ,col2 = 0;
    if(row1 % 2) col1 = (w-1) - m%w;
    else col1 = m%w;

    if(row2 %2) col2 = (w-1) - n%w;
    else col2 = n%w;
    
    cout << abs(row1- row2) + abs(col1-col2)  << endl; 
    return 0;
}