/*
title: 设计密码
Tag: 状态机 KMP
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 52, mod = 1e9 + 7;
int n;
char str[N];
int f[N][N];
int main(){
    cin >> n >> str + 1;
    int m = strlen(str+1);
    int next[N] = {0};
    // KMP求解next数组
    for(int i = 2, j = 0; i <= n; i++){
        while(j && str[i] != str[j+1]) j = next[j];
        if(str[i] == str[j+1]) j++;
        next[i] = j;
    }
    f[0][0] = 1; // 初始状态
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            for(char k= 'a';k<='z';k++){
                int u = j;
                while(u && k != str[u+1]) u = next[u];
                if(k == str[u+1]) u++;
                if(u < m) f[i+1][u] = (f[i+1][u] + f[i][j]) % mod;
            }
    int res = 0;
    for(int i=0;i<m;i++) res = (res + f[n][i]) % mod;
    cout << res << endl;

    return 0;
}