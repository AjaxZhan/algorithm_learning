#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5+10;
//状态：以a[i]结尾的公共子序列长度，甚至这里f[i]可以优化为一个变量
int f[N];
int n;
//处理接龙数列， 只存放开头和结尾的数字。
int l[N],r[N];
//辅助数组，存储最低位是i的接龙数列的长度，空间换时间。
int g[10];
int main()
{
    int n;
    scanf("%d", &n);

    char num[20];
    for (int i = 0; i < n; i ++ ){
        scanf("%s",num);
        l[i] = num[0]-'0';
        r[i] = num[strlen(num)-1] - '0';
    }
    int res = 0;
    for(int i=0;i<n;i++){
        f[i] = 1;
        f[i] = max(f[i],g[l[i]]+1);
        g[r[i]] = max(g[r[i]],f[i]);
        res = max(res , f[i]); 
    }
    printf("%d\n",n-res);
    
    return 0;
}