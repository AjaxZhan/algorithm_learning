/*
title: 友好城市
Tag: dp 最长上升子序列
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int,int> PII;
const int N = 5010;
int n;
PII city[N]; // 城市之间的对应关系
int f[N]; // 状态
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d %d",&city[i].first,&city[i].second);
    // 先对第一关键字排序
    sort(city+1,city+n+1);
    // 求LIS
    int res = 0;
    for(int i=1;i<=n;i++){
        f[i] = 1;
        for(int j=1;j<=i-1;j++)
            if(city[j].second < city[i].second) f[i] = max(f[i],f[j]+1);
        res = max(res,f[i]);
    }
    printf("%d\n",res);

    return 0;
}