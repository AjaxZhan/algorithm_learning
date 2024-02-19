/*
title: 国王
Tag: 状态压缩dp
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
// 开12是因为要枚举到n+1行， 从而n+1行的状态就是答案，不需要额外多一层循环
const int N = 12, M = 1 << N, K=110;
int n,m; 
vector<int>state; // 所有合法的状态
int cnt[M]; // 每个状态中1的个数
vector<int>stateMap[M]; // 每个状态可以转移到的其它状态
long long f[N][K][M]; // f[i][j][k] i行 摆了j个国王 第i行的状态是k的方案数

// 检查状态中是否存在连续的1
bool check(int state){
    for(int i=0;i<n;i++)
        if(state >> i & 1 && state >> (i+1) & 1)
            return false;
    return true;
}
// 计算状态中1的个数
int getKingCount(int state){
    int res = 0;
    for(int i=0;i<n;i++)
        if(state >> i & 1)
            res++;
    return res;
}

int main(){
    cin >> n >> m;    
    // 预处理所有合法的状态
    for(int i=0;i<1 <<n;i++){
        if(check(i)){
            state.push_back(i);
            cnt[i] = getKingCount(i);
        }
    }
    // 建立不同状态之间的转移关系
    for(int i=0;i<state.size();i++){
        for(int j=0;j<state.size();j++){
            int a = state[i], b = state[j];
            if((a & b) == 0 && check(a | b))
                stateMap[i].push_back(j);
        }
    }
    // dp
    f[0][0][0] = 1;
    for(int i=1;i<=n+1;i++) // 行
        for(int j=0;j<=m;j++) // 国王
            for(int s=0;s<state.size();s++) // 状态
                for(int t : stateMap[s]) // 从哪个状体转移过来
                {
                    int cnt_s = cnt[state[s]];
                    if(j>=cnt_s){
                        f[i][j][s] += f[i-1][j-cnt_s][t];
                    }
                }
    cout << f[n+1][m][0] << endl;
    return 0;
}