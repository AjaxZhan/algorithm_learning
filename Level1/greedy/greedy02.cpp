/*
区间分组
Acwing906
贪心算法
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 100010;
int n;
//存放区间，这里按照左端点进行排序
struct Range{
    int l,r;
    bool operator<(const Range &w)const{
        return l  < w.l;
    }
}range[N];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        range[i] = {l,r};
    }
    sort(range,range+n);
    priority_queue<int,vector<int>,greater<int>>heap;
    //小根堆存放：每个组中的右端点的最大值。堆顶：所有组中右端点值最小的组
    //对于每一个区间，看一下当前区间的左端点是否大于堆顶元素
    for(int i=0;i<n;i++){
        auto curr = range[i]; // 当前枚举的区间
        if(heap.empty() || heap.top() >=curr.l) 
            heap.push(curr.r);//新开一个组
        else{
            heap.pop();
            heap.push(curr.r);
            //加入组中，更新这个组的最大右端点值
        }
        
    }
    printf("%d\n",heap.size()); //输出组的数量
    return 0;
}