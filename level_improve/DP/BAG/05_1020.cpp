/*
title: 
from:
Tag:
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 22 , M = 80;
int n,m,k;
int f[N][M];
int main(){
    cin >> n >> m >> k;
    //初始化：为了让更新状态的时候不要使用到边界值
    memset(f,0x3f,sizeof f); 
    f[0][0] = 0;
    while(k--){
        int v1,v2,w;
        cin  >> v1 >> v2 >> w;
        //这里需要注意的点是，负数也是合法的。
        for(int j=n;j>=0;j--)
            for(int k=m;k>=0;k--)
                f[j][k] = min(f[j][k],f[max(0,j-v1)][max(0,k-v2)]+w); // max的含义：负数和0是等价的。
    }
    cout << f[n][m] << endl;
    return 0;

}