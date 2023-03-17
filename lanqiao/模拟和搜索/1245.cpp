/*
title: 特别数的和
from: acwing 1245
Tag: 暴力
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
long long res;
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        int x = i;
        while(x){
            int t = x%10;
            x/=10;
            if(t == 2 || t == 0 || t == 9 || t == 1){
                res+=i;
                break;
            }
        }
    }
    cout << res << endl;
    return 0;
}