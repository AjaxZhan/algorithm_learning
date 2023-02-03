/*
线性DP
最长上升子序列
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1010;
int n;
int a[N],f[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        f[i] = 1; // 每个数字的最长上升子序列至少是1
        for(int j=1;j<i;j++)
            if(a[j] < a[i]) f[i] = max(f[i],f[j]+1);

    }

    int res = 0;
    for(int i=1;i<=n;i++) res = max(res,f[i]);
    printf("%d\n",res);
    return 0;
}