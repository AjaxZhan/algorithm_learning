/*
title: 单词环
from: acwing 1165
Tag: SPFA判断负环 01分数规划问题
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
//建图方式：以字符串前后两个字符为点进行建立。以长度为边权。
const int N = 700, M =  100010;
int n;
int h[N],e[M],ne[M],idx,w[M];
double dist[N];//01分数规划
int cnt[N]; // 判断负权
bool st[N];
void add(int a, int b, int c){
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] =idx++;
}

bool check(double mid){
    //SPFA判断负环
    memset(st,0,sizeof st);
    memset(cnt,0,sizeof cnt);
    queue<int>q;
    //遍历所有点
    for(int i=0;i<676;i++){
        q.push(i);
        st[i] = true;
    }
    //经验特判
    int count = 0;
    while(q.size()){
        int t = q.front(); q.pop();
        st[t] = false;
        for(int i= h[t];~i;i=ne[i]){
            int j = e[i];
            if(dist[j] < dist[t] + w[i] - mid){
                dist[j] = dist[t] + w[i] - mid;
                cnt[j] = cnt[t] + 1;
                if(++count > 10000) return true;//经验特判
                if(cnt[j] >=N) return true;
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
    char str[1010];
    //逗号表达式时后面那个数，因此这里只要n为0就跳出循环
    //这里是多组测试数据
    while(scanf("%d",&n),n){
        //初始化：邻接表、索引
        memset(h,-1,sizeof h);
        idx = 0;
        for(int i=0;i<n;i++){
            scanf("%s",str);
            int len = strlen(str);
            //这个判断很容易忘记，其实当字符串长度<2就无法跟任何字符串连接
            if(len >=2){
                int left = (str[0] - 'a') * 26 + str[1] - 'a'; // 26进制数来表示
                int right = (str[len-2] - 'a') * 26 + str[len -1] - 'a';
                add(left,right,len);
            }
        }
        if(!check(0)) puts("No solution");
        else{
            double l = 0, r = 1000;
            while(r - l > 1e-4){
                double mid = (l + r) /2;
                if(check(mid)) l = mid;
                else r = mid;
            }
        }

    } 
    return 0;
}