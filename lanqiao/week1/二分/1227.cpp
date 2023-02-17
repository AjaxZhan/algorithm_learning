/*
title: 蓝桥杯备赛
from: acwing 1227. 分巧克力
Tag: 二分 蓝桥真题
Code:
思路：
找到能切除的最大变长。
边长越大，块数越小。块数 = [wi/x]*[hi/x]
要找到一个块数 >=k 的最大边长。可以二分。
二分性质：能切的块数>=k 找到满足这个条件的最大x
O(NlogH) 枚举每块巧克力，二分是
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100010;
int n,k; // 巧克力数量，小朋友数量
int h[N],w[N];
bool checked(int mid){
    int res = 0; // 分成的巧克力数量
    for(int i=0;i<n;i++){
        res+=(h[i]/mid)*(w[i]/mid); // 每一块分成变长为mid的巧克力
        if(res>=k) return true; //块数符合不符合要求
    }
    return false;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d%d",&h[i],&w[i]);
    int l = 1, r = 1e5; // 巧克力被分成的边长范围
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(checked(mid)) l= mid;
        else r = mid-1;
    }
    printf("%d",r);
    return 0;
}