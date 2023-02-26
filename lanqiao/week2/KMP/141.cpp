/*
title: 蓝桥杯复习
from: acwing 141 周期
Tag:
Code:
可以推出，循环节的长度为 i - ne[i];

*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N  =  1000000 + 10;
char str[N];
int ne[N];
int n;
void get_next(){
    for(int i=2,j=0;i<=n;i++){
        while( j && str[i]!=str[j+1]) j = ne[j];
        if(str[i] == str[j+1]) j++;
        ne[i] = j;
    }
}
int main(){
    int T = 1;
    while(scanf("%d",&n) && n){
        scanf("%s",str+1);
        get_next();
        printf("Test case #%d",T++);
        for(int i=1;i<=n;i++){
            int t = i - ne[i]; 
            if(i /t > 1&& i % t == 0){
                printf("%d %d\n",i,i/t);
            }
        }
        puts("");
        
    }
    return 0;
}