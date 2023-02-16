/*
title: 基础数论     
from: acwing 867. 分解质因数
Tag: 数学 分解质因数 试除法
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
void divide(int x){
    //利用性质：n中最多只包含一个大于根号n的质因子。
    //枚举约数
    for(int i=2;i<=x/i;i++){
        if(x % i ==0){
            int s = 0;
            while(x&i == 0){
                x/=i;
                s++;
            }
            printf("%d %d\n",i,s);
        }
    }
    //单独处理大于根号n的因子
    if(x>1) printf("%d %d\n",x,1);
    printf("\n");
}
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int x;
        scanf("%d",&x);
        divide(x);
    }
    return 0;
}