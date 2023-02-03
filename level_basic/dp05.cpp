/*
线性DP经典入门题：数字三角形
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 510,INF = 1e9;
int n;
int a[N][N];//数
int f[N][N];//状态

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            scanf("%d",&a[i][j]);
    //初始化，注意边界问题，每一行多初始化一个，保证最右边的数取最大值。
    for(int i=1;i<=n;i++)
        for(int j=0;j<=i+1;j++)
            f[i][j] = -INF;

    f[1][1] = a[1][1];
    for(int i=2;i<=n;i++)
        for(int j=1;j<=i;j++)
            f[i][j] = max(f[i-1][j-1] + a[i][j],f[i-1][j] + a[i][j]);
    
    int res = -INF;
    for(int i=1;i<=n;i++) res = max(res,f[n][i]);
    printf("%d\n",res);

    return 0;
}