/*
title:蓝桥杯备赛
from:acwing 797. 差分
Tag:差分 模板题
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100010;
int n,m;
int s[N];//读入的数组，把其当作是一个“前缀和数组”
int b[N];//差分数组
//要让前缀和数组某段区间内都加上一个常数，只需要操作差分数组，再累加即可
void insert(int l, int r, int val){
    b[l]+=val;
    b[r+1]-=val;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&s[i]); //读取要处理的“前缀和数组”
    for(int i=1;i<=n;i++) insert(i,i,s[i]); // 巧妙初始化差分数组
    while(m--){
        int l,r,c;
        scanf("%d%d%d",&l,&r,&c);
        insert(l,r,c);
    }
    for(int i=1;i<=n;i++) b[i]+=b[i-1]; //差分数组递推成新的“前缀和”
    for(int i=1;i<=n;i++) printf("%d ",b[i]);
    return 0;
}