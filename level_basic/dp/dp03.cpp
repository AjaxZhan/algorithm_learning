/*
多重背包问题
状态方程和完全背包问题相同，但是k的取值是0到s[i]。
优化版的话需要用单调队列。
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 110; // 朴素版，数据范围比较小的时候可以过

int n,m;
int v[N],w[N],s[N];
int f[N][N];

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> v[i] >> w[i] >> s[i];

    for(int i=1;i<=n;i++)
        for(int j =0;j <=m;j++)
            for(int k=0;k<=s[i] && v[i]*k <=j;k++)
                f[i][j] = max(f[i][j],f[i-1][j-v[i]*k] + w[i]*k);

    cout << f[n][m] << endl;    
    return 0;
}