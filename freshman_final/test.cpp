/*
Author：Cagur
Exercise Id：
Belong to : 
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    string str1;
    string str2;
    cin >> str1;
    cin >> str2;
    int cnt = 0;
    while(str1.size() && str1.find(str2) != string::npos){
        int pos = str1.find(str2);
        cnt++;
        str1 = str1.substr(pos + 1);
        // cout << cnt << endl;
        // cout << str1 << endl;
        // if(cnt ==4) break;
    }
    cout << cnt << endl;
    
    return 0;
}