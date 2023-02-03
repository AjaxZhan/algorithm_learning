/*
线性DP
最长上升子序列，附带保存最长序列
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1010;
int n;
int a[N],f[N];//存储数字和状态
int g[N];//存储转移
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    //分类标准：上一个数。
    for(int i=1;i<=n;i++){
        f[i] = 1; // 每个数字的最长上升子序列至少是1
        g[i] = 0; //只有一个数
        for(int j=1;j<i;j++)
            if(a[j] < a[i]){
                if(f[i] < f[j]+1) f[i] = f[j] + 1;
                g[i] = j; // 记录从哪个状态转移来的
            }
            

    }

    int k = 1 ;
    for(int i=1;i<=n;i++){
        if(f[k] < f[i]){
            k = i;
        }
    }
    printf("%d\n",f[k]);
    //倒输出方案
    for(int i=0,len = f[k];i<len;i++){
        printf("%d ",a[k]);
        k = g[k]; // 有点像链表的ne数组
    }
    return 0;
}