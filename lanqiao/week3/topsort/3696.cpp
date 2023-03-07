/*
title: 构造有向无环图
from: acwing 3696
Tag: 拓扑排序
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 200010,M= N;
int n,m,k,t;
int h[N],e[M],ne[M],idx,d[N],q[N];
//结构体存放无向边
struct Edge{
    int a;
    int b;
}edges[N];

//存放每个点在拓扑序中的位置。为了将无向图的指向做调整。
int pos[N];

void add(int a, int b){
    e[idx] = b;
    ne[idx] =h[a];
    h[a] = idx++;
}

bool topsort(){
    int hh =0, tt =-1;
    for(int i=1;i<=n;i++) if(!d[i]) q[++tt] = i;
    
    while(hh <= tt){
        int t = q[hh++];
        for(int i = h[t]; i!=-1;i = ne[i]){
            int j= e[i];
            d[j]--;
            if(!d[j]) q[++tt] = j;
        }
    }

    return tt == n-1;
}

int main(){
    scanf("%d",&t);
    while(t--){
        int cnt =0; // 记录无向边的条数
        scanf("%d%d",&n,&m);
        //每次都要重置一下d数组和q数组
        memset(h,-1,(n+1) * 4); // 小优化，不让太慢了
        memset(d,0,(n+1) * 4);
        idx=0;

        while(m--){
            int t ,a,b;
            scanf("%d%d%d",&t,&a,&b);
            if(!t) edges[cnt++] = {a,b};
            else{
                add(a,b);
                d[b]++;
            }
        }
        if(!topsort()) puts("NO");
        else{
            puts("YES");
            //有向图
            for(int i=1;i<=n;i++)
                for(int j = h[i];j !=-1;j=ne[j])
                    printf("%d %d\n",i,e[j]);
            //记录每个点在拓扑序中位置
            for(int i=0;i<n;i++) pos[q[i]] = i;
            //无向图
            for(int i=0;i<cnt;i++){
                int a = edges[i].a,b = edges[i].b;
                if(pos[a] > pos[b]) swap(a,b);
                printf("%d %d\n",a,b);
            }
            
        }

    }
    
    return 0;
}