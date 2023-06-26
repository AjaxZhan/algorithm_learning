/*
最长公共子序列
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1010;
int n,m;
char a[N],b[N]; // 注意是char类型啊哈
int f[N][N];
int main(){
    scanf("%d%d",&n,&m);
    scanf("%s%s",a+1,b+1);//坐标从1开始
    
    //由于是最大值，可以违背不重的原则
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            f[i][j] = max(f[i-1][j],f[i][j-1]);
            if(a[i] == b[j]) f[i][j] = max(f[i][j],f[i-1][j-1] + 1);
        }

    printf("%d\n",f[n][m]);
    return 0;
}