/*
title: 算法提高DP章节--数字三角形模型
from: 1015 摘花生
Tag: DP 线性DP
Code:
研究好状态就行了。
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 110; 
int t;
int r,c;
int w[N][N];
int f[N][N];
int main(){
    cin >> t;
    while(t--){
        int r,c;
        int n,m;
        cin >> r >> c;
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
                cin >> w[i][j];
        cin >> n >> m;
        
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
                f[i][j] = max(f[i-1][j]+w[i][j],f[i][j-1] + w[i][j]);
        cout << f[n][m] << endl;        
    }
    return 0;
}