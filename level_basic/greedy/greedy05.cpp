/*
贪心算法
排序不等式
排队取水问题 Acwing913.
如何证明：按照从小到大排序，总时间最小？
证明：调整法。
    假设最优解不是按照从小到大排序，必然存在两个相邻的人，ti> ti+1。
    交换ti 和ti+1只会影响这两个人，不会影响后面的人。
        交换前：ti(n-i) + ti+1(n-i-1)
        交换后: ti+1(n-i) + ti(n-1-i)
        减法后 > 0 说明 交换后时间更短，与这个序列是最优解矛盾。
    因此，最优解一定是从小到大排序的。
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 100010;
int n;
int t[N];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&t[i]);
    sort(t,t+n);
    LL res = 0;
    for(int i=0;i<n;i++) res+=t[i]*(n-1-i);
    printf("%lld\n",res);
    return 0;
}