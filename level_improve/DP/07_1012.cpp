/*
title: 友好城市
from: acwing 1012
Tag: LIS
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int,int> PII;
const int N = 5010;
int n;
PII q[N];
int f[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&q[i].first,&q[i].second);
    sort(q+1,q+n+1);
    int res = 0;
    for(int i=1;i<=n;i++){
        f[i] = 1;
        for(int j=1;j<i;j++){
            if(q[i].second > q[j].second)  f[i] = max(f[i], f[j]+1);
        }
    }    
    for(int i =1;i <=n;i++) res =max(res,f[i]);
    cout << res << endl;
    return 0;
}