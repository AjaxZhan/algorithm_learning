/*
title: 玉米田
Tag: 状态压缩DP
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int N =14, M = 1 << 12, MOD = 1e8;
int n,m;
vector<int>state; // 状态
vector<int>stateMap[M]; // 转移到的状态
long long f[N][M]; // dp状态
int invalid[M]; // 保存非法状态

// 检查状态中是否存在连续的1
bool check(int state){
    for(int i=0;i<m;i++)
        if(state >> i & 1 && state >> (i+1) & 1)
            return false;
    return true;
}

int main(){
    cin >> n >> m;
    // 读取地图，初始化非法状态
    for(int i=1;i<=n;i++){
        // 二进制的位数
        for(int j=0;j<m;j++){
            int t;
            cin >> t;
            invalid[i] += !t << j;
        }
    }   
    // 预处理所有合法的状态，位数是列数
    for(int i=0;i<1 <<m;i++){
        if(check(i)){
            state.push_back(i);
        }
    }
    // 建立不同状态之间的转移关系
    for(int i=0;i<state.size();i++){
        for(int j=0;j<state.size();j++){
            int a = state[i], b = state[j];
            if((a & b) == 0) // 两个状态没有交集
                stateMap[i].push_back(j); // i 转移到 j
        }
    }
    // dp
    f[0][0] = 1;
    for(int i=1;i<=n+1;i++){ // 行
        for(int j=0;j<state.size();j++){ // 状态
            if(invalid[i] & state[j]) continue; // 非法状态
            for(int k: stateMap[j]){ // 上一个状态 
                f[i][j] = (f[i][j] +  f[i-1][k])%MOD;
            }
        }
    }
    cout << f[n+1][0]<< endl;
    
    return 0;
}