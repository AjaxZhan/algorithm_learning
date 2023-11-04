/*
title: 分成互质组
from: acwing 1118
Tag: dfs 欧几里得
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 10;
int n;
int p[N];
int group[N][N];
int ans = N;
bool st[N];
//用欧几里得算法来判断两个数互质
int gcd(int a, int b){
    return b ? gcd(b,a%b) : a;
}

//组内所有元素和第i个数互质
bool check(int group[],int gc,int i){
    for(int j =0;j<gc;j++){
        if(gcd(p[group[j]],p[i])  > 1) return false;
    }
    return true;
}

void dfs(int u , int gc, int tc, int start){
    if(u >=ans) return; //组数量大于答案
    if(tc == n){
        //所有数都分组成功
        ans = u;
    }
    bool flag = true;
    for(int i=start;i<n;i++){
        if(!st[i] && check(group[u],gc,i)){
            st[i] = true;
            group[u][gc] = i;
            dfs(u,gc+1,tc+1,i+1);
            st[i]  = false;

            flag = false;
        }
    }
    if(flag) dfs(u+1,0,tc,0);

}

int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> p[i];
    //搜第一组，组内元素为0，当前搜了0元素，start下标保证组合顺序
    dfs(1,0,0,0);
    
    cout << ans << endl;
    return 0;
}