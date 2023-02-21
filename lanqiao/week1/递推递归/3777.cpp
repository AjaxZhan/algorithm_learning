/*
title: 蓝桥杯复习
from:  acwing 3777  砖块
Tag: 递推
Code: 也是开关问题，跟翻硬币类似。这种题也可以用高斯消元来求解。
这题有两种可能性，并且可能无解，因此需要多一步操作。

*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 210;
int n;
string s;
void turn(char &c){
    if(c == 'W') c= 'B';
    else c = 'W';
}
bool check(string s, char c){ //封装
    vector<int>res;
    for(int i=0;i<n-1;i++){
        if(s[i]!=c){
            res.push_back(i);
            turn(s[i]);
            turn(s[i+1]);
        }
    }
    if(s.back() != s[0]) return false; 
    
    cout << res.size() << endl;
    if(res.size()) for(auto x : res)  cout << x + 1 << " " ;
    cout <<endl;
    return true;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int res = 0;
        cin >> n;
        cin >> s;
        if(!check(s,'W')&& !check(s,'B')) puts("-1");

    }
    
    return 0;
}