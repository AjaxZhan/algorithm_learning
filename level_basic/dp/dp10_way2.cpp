/*
计数DP--整数划分
状态方程第二种
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1010, MOD =1e9+7;
int n;
int f[N][N];

int main(){
    cin >> n;
    f[0][0] = 1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++) // i个数最多表示成i个数的和
            f[i][j] = (f[i-1][j-1] + f[i-j][j])% MOD;

    int res = 0;
    for(int i=1;i<=n;i++) res = (res + f[n][i])%MOD;
    cout  << res << endl; 
    return 0;
}