/*
title: 宠物小精灵之收服
from: acwing 1022
Tag: 01BAG 二维费用
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1010,M = 510;
int n,V1,V2; //精灵球、体力
int f[N][M]; // 优化成二维的
int main(){
    cin >> V1 >> V2 >> n;
    for(int i=0;i<n;i++){
        int v1, v2;
        cin >> v1 >> v2;
        for(int j=V1;j>=v1;j--){
            //坑点：由于皮卡丘体力不能为0，因此每次的体力值要先-1，保证其不为0.
            for(int k=V2-1;k>=v2;k--){
                f[j][k] = max(f[j][k],f[j-v1][k-v2] +1);
            }
        }
    }
    //最多收复的小精灵个数
    cout << f[V1][V2-1] << ' ';
    //皮卡丘体力剩余最大值，即耗费体力最少

    int k = V2-1;//k为耗费最小的体力
    while(k > 0 && f[V1][k-1] == f[V1][V2-1]) k--; //下一个等于，就能走过去
    cout << V2 - k << endl;
    return 0;
}