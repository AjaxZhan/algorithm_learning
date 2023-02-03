/*
区间dp--石子合并
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 310;
int n;
int s[N]; // 前缀和
int f[N][N]; // 状态

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&s[i]);
    //处理前缀和
    for(int i=1;i<=n;i++) s[i]+=s[i-1];
    //长度从小到大来枚举状态
    for(int len = 2; len <= n; len ++) // 枚举长度,1可以不枚举
        for(int i=1;i+len-1 <=n;i++ ){//枚举起点
            int l = i, r = i+len -1;
            f[l][r] = 1e8; //初始化 
            for(int k = l;k<r;k++)//枚举分界点
                f[l][r] = min(f[l][r],f[l][k] + f[k+1][r] +s[r] - s[l-1]); 
        }
    
    printf("%d\n",f[1][n]);

    return 0;
}