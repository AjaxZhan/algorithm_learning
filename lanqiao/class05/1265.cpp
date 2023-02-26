/*
title: 蓝桥杯复习
from: acwing 1265 数星星
Tag: 树状数组
Code: 本质上是抽象出树状数组的模型
发现一个维度不要考虑，因为题目给出顺序是按照正向顺序给的。
存储：前面有多少个星星
求等级即求：a1 - ax前缀和
更新：枚举完一个星星后需要加回去，因此就是单点修改。
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N  = 32010;
int n;
int c[N];
int level[N];
int lowbit(int x){
    return x &-x;
}
int query(int final){
    int res = 0;
    for(int i= final;i>0;i-=lowbit(i)) res+=c[i];
    return res;
}
void add(int a, int b){
    //x的坐标范围，是N不是n
    for(int i=a;i<=N;i+=lowbit(i)) c[i]+=b;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x, y;
        //细节：原题下标从0开始，因此要加上1
        scanf("%d%d",&x,&y);
        x++,y++;//纵坐标无所谓其实
        level[query(x)]++;
        add(x,1);
    }
    for(int i=0;i<n;i++){
        printf("%d\n",level[i]);
    }


    return 0;
}