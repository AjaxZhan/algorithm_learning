/*
title: 算法基础之数论
from: acwing893 集合--Nim游戏
Tag: 博弈论 Nim游戏 SG函数
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
using namespace std;
const int N = 110,M = 10010; //石头堆数 数量
int n,m;
int f[M],s[N]; 
//S存储每次可以选择石头的集合，f存储的是所有可能出现过的SG值


//采用记忆化搜索的方式来求SG
int sg(int x){
    if(f[x]!= -1) return f[x]; // 搜索过了，可以证明在石头堆中，只要选择的方法数集合一样，那么sg都是相同的。
    
    unordered_set<int>S; // 存储所有可以到的局面

    for(int i=0;i<m;i++){
        int total= s[i]; //当前数的个数
        if(x >=total) S.insert(sg(x-total)); 
        //延申到终点的sg值后，  再从后往前排查出所有数的sg值
    }
    //选出最小的没有出现的自然数
    for(int i = 0;;i++)
        if(!S.count(i)) return f[x] = i;

}

int main(){
    cin >> m;
    for(int i=0;i<m;i++) cin >> s[i];

    cin >> n;
    memset(f,-1,sizeof f); //-1表示sg没有被搜索过

    int res = 0;
    for(int i=0;i<n;i++){
        int x;
        cin >> x; //读取第i堆石头中的个数

        res^=sg(x); //Nim游戏
    }
    if(res) puts("Yes");
    else puts("No");
    return 0;
}