/*
title: 金明的预算方案
Tag: 分组背包
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#define v first
#define w second
using namespace std;
typedef pair<int,int> PII;
const int N = 70 , M = 32010;
int n, m;
PII master[N];
vector<PII> slave[N];
int f[M];
int main(){
    cin >> m >> n;
    for(int i=1;i<=n;i++){
        int v,w,q;
        cin >> v >> w >> q;
        w*=v; // 计算出实际的价值
        if(!q){ // 主件
            master[i] = {v,w};
        }else{ 
            slave[q].push_back({v,w});
        }
    }

    for(int i=1;i<=n;i++){
        // 剪掉价值为0
        if(!master[i].v) continue;
        for(int j=m;j>=0;j--)
            // 二进制枚举
            for(int k=0;k< (1 << slave[i].size());k++){
                int v = master[i].v, w = master[i].w;
                for(int pos = 0; pos< slave[i].size();pos++){
                    if(k >> pos &1){
                        v+=slave[i][pos].v;
                        w+=slave[i][pos].w;
                    }
                }
                if(j >= v) f[j] = max(f[j],f[j-v]+w);
            }
    }

    cout << f[m] << endl;
    return 0;
}