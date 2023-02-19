/*
title: 蓝桥杯复习
from: acwing 1238 日志统计
Tag: 双指针 蓝桥真题 滑动窗口
思路：按照时间段进行排序，枚举时间段，统计时间段内id出现的次数。
暴力做法要枚举时间段 + 遍历ID，实际上ID的增加类似一个滑动窗口，因此不用遍历，只需要对头尾操作。
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int,int> PII; //时间段，id
#define x first
#define y second
const int N = 100010;
int n,d,k;
int cnt[N];//动态记录区间内的点赞数
PII logs[N]; // 记录帖子，按照时间段排序
bool st[N]; // 记录是否为热帖

int main(){
    scanf("%d%d%d",&n,&d,&k);
    for(int i=0;i<n;i++) scanf("%d %d",&logs[i].x,&logs[i].y);
    
    //时间段排序
    sort(logs,logs+n);

    //枚举时间段

    for(int i=0,j=0;i<n;i++){
        int id = logs[i].y;
        cnt[id]++;
        //动态操作，只操作首尾
        while(logs[i].x - logs[j].x >= d){
            cnt[logs[j].y]--;
            j++;
        }
        if(cnt[id] >= k) st[id] = true; 
    }

    //找到热帖
    for(int i=0;i<N;i++)
        if(st[i]) printf("%d\n",i);

    return 0;
}