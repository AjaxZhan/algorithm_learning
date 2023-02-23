/*
title: 蓝桥杯复习
from: acwing 154 滑动窗口
Tag: 单调队列
Code: 
作用：可以用于多重背包的优化
题意：每一次将滑动窗口内的最值输出出来。
暴力：O(N*K)，但是数据范围1e6 显然不行。
例如：求最小值而窗口内是3 -1 -3 ，3 和 -1 都是没用的。即只要前面的 > 新进入 的，就没用。
换而言之，队列一定是单调递增的。一个严格单调上升队列的最小值：队头元素。
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e6+10;
int n,k;
int a[N],q[N]; //a存放原数组 ，q是存放下标的单调队列
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    //先求最小值，那么前面的数如果比新加入的数大，就没有意义，所以是单调递增。在对头取最小值。
    int hh = 0, tt =  -1;
    for(int i=0;i<n;i++){
        //队头是否划出窗口,不用while：每次就移动一位
        if(hh <= tt && i-k+1 > q[hh]) hh++;

        //判断单调性
        while(hh <=tt && a[q[tt]] >= a[i]) tt--;
        
        q[++tt] = i; // 入队

        //例如k=3,i>=2 才输出
        if( i>= k-1) printf("%d ",a[q[hh]]);
    }
    puts("");

    //最大值，那么前面的数如果比新加入的数小，就没有意义，所以是单调递减。在对头取最大值。
    hh = 0, tt =  -1;
    for(int i=0;i<n;i++){
        //队头是否划出窗口,不用while：每次就移动一位
        if(hh <= tt && i-k+1 > q[hh]) hh++;

        //判断单调性
        while(hh <=tt && a[q[tt]] <= a[i]) tt--;
        
        q[++tt] = i; // 入队

        //例如k=3,i>=2 才输出
        if( i>= k-1) printf("%d ",a[q[hh]]);
    }
    puts("");
    return 0;
} 