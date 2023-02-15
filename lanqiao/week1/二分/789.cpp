/*
title:蓝桥杯备赛
from:acwing 789. 数的范围
Tag: 二分 整数二分
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100010;
int n,q;
int a[N];
int main(){
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    while(q--){
        int k;
        scanf("%d",&k);
        //二分查找左端点
        int l = 0,r=n-1;
        while(l < r){
            int mid = l+r  >> 1;
            if(a[mid]>=k) r = mid;
            else  l = mid+1;
        }
        if(a[l]!=k) cout<< "-1 -1" << endl;
        else{
            cout << l << " ";
            l = 0,r=n-1;
            while(l<r){
                int mid = l + r +1 >> 1;
                if(a[mid]<=k) l = mid;
                else r = mid-1;
            }
            cout << l << endl;
        }
    }
    return 0;
}