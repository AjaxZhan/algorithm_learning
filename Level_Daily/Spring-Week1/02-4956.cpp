/*
2023蓝桥杯真题--冶炼金属
二分解法
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int binary_s(int a , int b){
    int l = 1,r = 1e9+1; // 右边界，考虑到求最大值的时候有b-1=0，因此最大值+1
    while(l < r){
        int mid = l + r >> 1;
        if(a/mid <= b) r = mid;
        else l = mid + 1;
    }
    return r;
}
int main()
{
    scanf("%d", &n);
    int v_min=1,v_max=1e9;
    while (n -- ){
        int a, b;
        scanf("%d%d", &a, &b);
        v_min = max(v_min,binary_s(a,b));
        v_max = min(v_max,binary_s(a,b-1)-1);
    }
    printf("%d %d",v_min,v_max);
    
    return 0;
}