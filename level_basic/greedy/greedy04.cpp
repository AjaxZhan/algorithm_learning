/*
贪心算法 - HuffmanTree
合并果子--Acwing148.
不同区间DP石子合并的是，这道题是任意合并，不用相邻
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    priority_queue<int,vector<int>,greater<int>> heap;
    while(n--){
        int x;
        scanf("%d",&x);
        heap.push(x);
    }
    //每次挑出两个最大值，合并
    int res = 0;
    while(heap.size() > 1){
        int a = heap.top(); heap.pop();
        int b = heap.top(); heap.pop();
        res+=(a+b);
        heap.push(a+b);
    }
    printf("%d\n",res);
    return 0;
}