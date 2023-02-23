/*
title: 算法提高DP章节--数字三角形模型
from: acwing 1018 最低通行费
Tag: DP 线性DP  
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 110,INF =1e9;
int n;
int w[N][N];
int f[N][N];
int main(){
    cin >> n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)  
            cin >> w[i][j];

    //注意边界问题，更新的时候可能从左边第0列更新过来
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(j == 1 && i == 1) f[i][j] = w[i][j];
            else{
                f[i][j] = INF;
                if(i > 1) f[i][j] = min(f[i][j],f[i-1][j] +w[i][j]);
                if(j > 1) f[i][j] = min(f[i][j],f[i][j-1] + w[i][j]);
            }
    cout << f[n][n] << endl;
    return 0;
}