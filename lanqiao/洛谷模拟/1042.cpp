/*
title: 乒乓球
from: 洛谷 1042 NOIP2003普及组
Tag: 模拟 字符串
Code:
代码特点：封装性好。
本题其实就是将字符串进行处理，考察的还是代码能力。
    1. 正确理解乒乓球的规则：既要又要的关系。既要比分到11，又要abs>=2。比如11 ： 10 就不行。
    2. 处理方案；采用一个字符一个字符读。
    3. 翻译出规则，(l >= n || r >=n ) && abs(l- r) >= 2  而不是 %的关系。
    4. 如何处理最后一组数据：循环外处理即可。
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
char str[100010];
int cnt;
void show(int n){
    //对字符串进行处理
    int l = 0 ,r = 0;
    for(int i=0;i<cnt;i++){
        if(str[i] == 'W') l ++;
        else r++;
        if((l >= n || r >=n ) && abs(l- r) >= 2){
            printf("%d:%d\n",l,r);
            l=0,r=0;
        }
    }
    //如何处理最后的比分？循环外即可！
    printf("%d:%d\n",l,r);
}
int main(){
    char ch;
    while(cin >> ch && ch != 'E'){
        if(ch == 'W' || ch == 'L') str[cnt++] = ch;
    }

    show(11);
    puts("");
    show(21);

    
    return 0;
}