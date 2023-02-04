/*
计数DP--整数划分
完全背包思路
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1010, MOD=  1e9 + 7;
int n;
int f[N]; //完全背包一维优化
int main(){
    cin >> n;
    f[0] = 1; //一个都不选的时候，容量为0，只有一种方法就是不选。
    //其它情况都是一个都不选的情况下容量大于0，方法都是0
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++) // 从i开始枚举
            f[j] = (f[j] + f[j-i]) %MOD;
    cout << f[n] << endl;

    return 0;
}