/*
title: 拦截导弹
Tag: dp LIS
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1010;
int n;
int q[N]; // 导弹序列
int f[N]; // 状态
int g[N]; // 存储现有的最长下降子序列的结尾的数
int main(){
    while(cin >> q[n]) n++;
    // 第一问：最长下降子序列长度
    int res = 0;
    for(int i=0;i<n;i++){
        f[i] = 1;
        for(int j=0;j<i;j++){
            if(q[j] >= q[i]) f[i] = max(f[i],f[j]+1);
        }
        res = max(res,f[i]);
    }
    cout << res << endl;
    // 第二问：最长下降子序列个数
    // 贪心：让子序列结尾尽可能的大，转换成题干问题的对偶问题
    int cnt = 0;
    for(int i=0;i<n;i++){
        int k = 0;
        while(k < cnt && g[k] < q[i]) k++;
        g[k] = q[i];
        if(k >= cnt) cnt++;
    }
    cout << cnt << endl;

    return 0;
}