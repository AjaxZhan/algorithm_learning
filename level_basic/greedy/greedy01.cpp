/*
贪心算法--区间问题
区间选点 Acwing905
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100010;
int n;
//定义一个区间的结构体，重写运算符
struct Range{
    int l;
    int r;
    bool operator<(const Range& W)const{
        return r<W.r;
    }
}range[N];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        range[i] = {l,r};
    }
    //按照右端点排序
    sort(range,range+n);
    //res表示当前选择点的数量，ed表示上一个点的右端点
    int res = 0, ed = -2e9;
    for(int i=0;i<n;i++)
        if(range[i].l > ed){
            res ++;
            ed = range[i].r;
        }
    printf("%d\n",res);
    return 0;
}