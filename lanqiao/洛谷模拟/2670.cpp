/*
title: 扫雷游戏
from: 洛谷2670 NOIP2015普及组
Tag: 搜索 字符串 模拟
Code:
一道普通的搜索题，范围小暴力即可。
吸取的教训是，老老实实用int存数量，如果是*直接输出即可。
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 110;
int n,m;
char g[N][N];
int cnt[N][N];
int dx[8] = {0,-1,-1,-1,0,1,1,1};
int dy[8] = {-1,-1,0,1,1,1,0,-1}; 
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        for(int j = 1;j<=m;j++)
            cin >> g[i][j];
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(g[i][j] == '*'){
                cout << g[i][j];
            }
            else{
                for(int k = 0;k<8;k++){
                    int xx = i + dx[k];
                    int yy = j + dy[k];
                    if(xx > 0 && xx <= n && yy >0 && yy<=m && g[xx][yy] == '*') cnt[i][j] ++;
                }
                cout << cnt[i][j];
            }
        }
        cout <<  endl;
    }
    
    return 0;
}