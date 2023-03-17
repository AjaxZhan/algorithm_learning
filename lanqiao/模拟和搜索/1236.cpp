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
    sort(b,b+n); 
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
        //答案格式：(left+1)(N-right)
        //特判一下如果找不到
        if(a[l] >=bb) l = -1;
        left = l;
        //二分有多少个数大于bj
        l = 0 ,r = n-1;
        while(l < r){
            int mid = l+r >> 1;
            if(c[mid] > bb) r= mid;
            else l = mid+1;
        }
        if(c[l]<=bb) r = n;
        right = r;
        res+=(long long)(left+1)*(n-right);
    }
    cout << res<< endl;
    return 0;
}