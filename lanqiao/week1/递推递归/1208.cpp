/*
title: 蓝桥杯复习
from: acwing 1208. 翻硬币
Tag: 递推
Code: 费解开关的简化版，递推即可
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 120;
int n;
char st[N],dest[N];
void turn(int i){
    if(st[i] == '*') st[i] = 'o';
    else st[i] = '*';
}
int main(){
    cin >> st >> dest;
    n = strlen(st);
    int res = 0;
    for(int i=0;i<n-1;i++){
        if(st[i]!=dest[i]){
            turn(i);
            turn(i+1);
            res++;
        }
    }
    cout << res << endl;
    return 0;
}