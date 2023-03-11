/*
title: 观光奶牛
from: acwing 361
Tag: 01分数规划 负环 二分
Code:

*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
const int N = 1010 , M = 5010;
using namespace std;
int n,m;
int wf[N]; //表示点权
int h[N],e[M],ne[M],wt[M],idx;//表示边权
double dist[N]; // 转化后的距离是一个小数类型
bool st[N];
int cnt[N]; // 判断负环，即判断每条边出现的个数
void add(int a, int b, int c){
    e[idx] = b;
    wt[idx] =c;
    ne[idx] = h[a];
    h[a] = idx++;
}
bool check(double mid){
    //判断新图是否是负环

    //初始化：距离、状态、判断数组
    memset(dist,0,sizeof dist);
    memset(st,0,sizeof st);
    memset(cnt,0,sizeof cnt);

    queue<int>q;
    for(int i=1;i<=n;i++){
        q.push(i);
        st[i] = true;
    }

    while(q.size()){
        int t = q.front();q.pop();
        st[t] = false;
        for(int i=h[t];~i;i=ne[i]){
            int j = e[i];
            if(dist[j] < dist[t] + wf[t] - mid*wt[i]){
                dist[j] = dist[t] + wf[t] - mid * wt[i];
                cnt[j] = cnt[t] +1;
            
                if(cnt[j]>=n) return true;
                if(!st[j]){
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return false;
}


int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&wf[i]);
    memset(h,-1,sizeof h);
    for(int j=0;j<m;j++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
    }
    //实数二分
    double l = 0 ,r = 1e6;
    while(r - l > 1e-4){
        double mid = (l + r) /2;
        if(check(mid)) l = mid;
        else r= mid;
    }

    printf("%.2lf\n",l);

    return 0;
}