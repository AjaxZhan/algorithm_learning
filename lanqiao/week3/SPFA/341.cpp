/*
title: 最优贸易
from: acwing 341
Tag: SPFA
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 100010,M = 2000010;
int n,m;
int dmin[N],dmax[N];
bool st[N];
int h[N],e[M],ne[M],hr[N],idx;//hr表示反向建图
int w[N];//表示每个点的价值，这道题的价值是存点上的
void add(int *h, int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
void spfa(int *d , int start, int *h, bool flag){
    //dist，开始节点，h数组，正反向
    queue<int>q;
    //对st数组进行初始化
    memset(st,0,sizeof st);
    //如果是正向建图，初始化INF
    if(flag) memset(d,0x3f,sizeof dmin);
    q.push(start);
    st[start] = true;
    d[start] = w[start];
    while(q.size()){
        int t = q.front();
        q.pop();
        st[t] = false;
        for(int i = h[t]; i!=-1;i= ne[i]){
            int j = e[i];
            if(flag && d[j] >min(d[t],w[j]) || !flag && d[j] < max(d[t],w[j])){
                if(flag) d[j] = min(d[t],w[j]);
                else d[j] = max(d[t],w[j]);
                if(!st[j]){
                    st[j] = true;
                    q.push(j);
                }
            }
        }
    }
}
int main(){

    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof h);
    memset(hr,-1,sizeof hr);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    while(m--){
        int a, b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(h,a,b),add(hr,b,a);
        if(c == 2) add(h,b,a),add(hr,a,b); 
    }
    spfa(dmin,1,h,true);
    spfa(dmax,n,hr,false);
    int res = 0;
    for(int i=1;i<=n;i++) res= max(res,dmax[i] - dmin[i]);
    printf("%d\n",res);
    return 0;
}