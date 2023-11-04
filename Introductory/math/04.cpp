/*
title: 基础数论
from: acwing 869. 试除法求约数
Tag: 数学 约数
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> get_divisors(int n){
    vector<int>res;
    for(int i=1;i<=n/i;i++){
        if(n %i == 0) res.push_back(i);
        if(i!=n/i) res.push_back(n/i); // 不能是自己
    }
    sort(res.begin(),res.end());
    return res;
}
int main(){
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        auto res = get_divisors(x);
        for(auto t: res) cout << t << " ";
        cout << endl;
    }
    return 0;
}