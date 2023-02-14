/*
title:蓝桥杯备赛
from:acwing3729. 改变数组元素
Tag:差分、区间合并
思路：
    区间合并O(NlogN)
    差分O(N)
        题目的+0操作可以用初始化0来完成，所以重点是在第二步将末尾元素都变成1
        由于这里可以将第二步用差分来做，维护的是操作的次数，只要操作个数>1，输出技巧:!!
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 200010;
int n;
//差分数组
int b[N];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        memset(b,0,(n+1)*4); // 初始化只需要n+1即可
        for(int i=1;i<=n;i++){
            int a;
            scanf("%d",&a);
            //差分
            int l = max(1,i-a+1),r = i;
            b[l]++,b[r+1]--;
        }
        for(int i=1;i<=n;i++){
            b[i]+=b[i-1];
            printf("%d ",!!b[i]); // 取两次非
        }
        puts("");
    }
    return 0;
}