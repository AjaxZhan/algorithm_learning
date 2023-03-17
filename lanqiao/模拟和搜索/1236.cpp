/*
title: 递增三元组
from: acwing 1236
Tag: 枚举 前缀和 二分
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100010;
int n;
int a[N],b[N],c[N];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
    for(int i=0;i<n;i++) scanf("%d",&c[i]);
    long long res = 0;
    sort(a,a+n);
    sort(c,c+n);
    // sort(b,b+n);
    //枚举b
    for(int i=0;i<n;i++){
        int bb = b[i];
        int left = 0,right = 0;
        //二分有多少个数小于bj
        int l = 0,r = n-1;
        while(l < r){
            int mid = l+r+1>> 1;
            if(a[mid] < bb) l = mid;
            else r = mid-1;
        }
        //答案格式：(left+1)(N-right+1)
        //特判一下如果找不到
        if(a[l] >=bb) left = -1;
        left = l+1;
        //二分有多少个数大于bj
        l = 0 ,r = n-1;
        while(l < r){
            int mid = l+r >> 1;
            if(c[mid] > bb) r= mid;
            else l = mid+1;
        }
        if(a[r]<=bb) right = n+1;
        right = r+1;
        res+=(left+1)*(n-right+1);
    }
    cout << res<< endl;
    return 0;
}