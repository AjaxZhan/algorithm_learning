/*
线性DP
最短编辑距离
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1010;
int n,m; // 字符串长度
char a[N],b[N];
int f[N][N]; //状态
int main(){
    scanf("%d%s",&n,a+1); // 状态转移方程有i-1，那从1开始
    scanf("%d%s",&m,b+1);

    //边界情况
    for(int i=0;i<=m;i++) f[0][i] = i; //只能进行新增操作
    for(int i=0;i<=n;i++) f[i][0] = i; //只能进行删除操作

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            f[i][j] = min(f[i-1][j]+1,f[i][j-1]+1);
            if(a[i] == b[j]) f[i][j] = min(f[i][j],f[i-1][j-1]); // 不需要最后一次操作
            else f[i][j] = min(f[i][j],f[i-1][j-1]+1);
        }

    printf("%d\n",f[n][m]);
    return 0;
}