/*
title:基础数论
from:866. 试除法判定质数
Tag: 数学 质数
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
bool is_prime(int x){
    if(x < 2) return false;
    for(int i=2;i<=x/i;i++){
        if(x % i == 0) return false;
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        if(is_prime(x)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}