/*
最长上升子序列--优化
数据范围：1e5，所以上次的O(N^2)过不了
优化：转成O(N*logN)
其实已经变成贪心+二分了，跟dp没啥关系。
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100010;
int n;
int a[N]; // 存储数
int q[N]; // 存储不同长度下，所有不同长度上升子序列结尾的最小值
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    int len = 0; // 存放当前的最大长度
    q[0] = -2e9; // 哨兵
    for(int i=0;i<n;i++){
        int l=0,r=len;
        while(l < r){
            int mid = l + r + 1 >>1;
            if(q[mid] < a[i]) l = mid;
            else r = mid-1;
        }
        len = max(len,r+1); // 更新最大值
        q[r+1] = a[i]; // 接到某个数后面，
    }

    printf("%d\n",len);

    return 0;
}