/*
title: 城市通电
from: acwing 3728
Tag: 最小生成树 Prim 虚拟源点
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 2010;
#define x first
#define y second
typedef pair<int,int> PII;
typedef long long LL;
int n;
int wk[N],wc[N],fa[N]; // 分别表示电线、电站、父节点
PII p[N];//坐标
bool st[N];
LL dist[N];
vector<int>ans1; // 存电站方案
vector<PII>ans2; // 存电线方案

//获取两点之间的权值（曼哈顿距离 * 电线权值）
LL get_dist(int a, int b){
    int dx = abs(p[a].x - p[b].x);
    int dy = abs(p[a].y - p[b].y);
    return (LL) (dx + dy) * (wk[a] + wk[b]);
}

LL prim(){
    memset(dist,0x3f,sizeof dist);
    //建立虚拟原点
    dist[0] = 0;
    st[0] = true;

    //更新到原点的距离
    for(int i=1;i<=n;i++)
        dist[i] = wc[i];
    
    //Prim
    LL res  = 0;
    for(int i=0;i<n;i++){
        int t = -1;
        //找到不在集合中的距离最近的点
        for(int j=1;j<=n;j++)
            if(!st[j] && (t == -1 || dist[j] < dist[t]) )
                t = j;
        
        //更新答案，加入集合
        res+=dist[t];
        st[t] = true;
        
        //如果没有父节点，说明是和虚拟原点连接
        if(!fa[t]) ans1.push_back(t);
        else ans2.push_back({fa[t],t});
        //更新到其它点的距离
        for(int j=1;j<=n;j++)
            if(dist[j] > get_dist(t,j)){
                dist[j] = get_dist(t,j);
                fa[j] = t;

            }
    }
    return res;
}


int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&p[i].x,&p[i].y);
    for(int i=1;i<=n;i++)
        scanf("%d",&wc[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&wk[i]);
    
    printf("%lld\n",prim());
    printf("%d\n",(int)ans1.size());
    for(auto x : ans1) printf("%d ",x);
    printf("\n%d\n",(int)ans2.size());
    for(auto &pos : ans2){
        printf("%d %d\n",pos.x,pos.y);
    }

    

    return 0;
}