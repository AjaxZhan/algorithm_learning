/*
title: 蓝桥杯复习
from: acwing 240. 食物链
Tag: 并查集
Code:
思路：用一个并查集维护每个点到根节点的距离，带权并查集。
记录每个点和根节点的关系，即可确定任意两个点的关系--用每个点到根节点的距离表示和根节点的关系。
不妨定义：到根节点的距离是1表示吃根节点，到根距2，被根吃，到根3，与根同类。
即x吃y则，x到y的距离为1.
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 50010;
int n,k,res;
int p[N],d[N]; // d 表示到父节点的距离，由于路径压缩，所以表示到根节点的距离
int find(int x){
    //核心函数：递归，关键是要理解每次距离是从上一层返回回来，所以最后d会是指向根节点的距离。
    if(p[x]!=x){
        int u = find(p[x]); //找到根节点
        d[x] += d[p[x]]; //dx的距离更新为上一层的距离，由于递归，最后结果就是到根节点的距离
        p[x] = u; //将父节点指向根节点
    }
    return p[x];
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) p[i] = i;
    while(k--){
        int type,x,y; 
        scanf("%d%d%d",&type,&x,&y);
        if(x > n || y > n )res++;
        else{
            int px = find(x), py = find(y); // 找到根节点
            if(type == 1){ // 同类 : %3相同
                if(px == py && (d[x] - d[y]) % 3) res++;
                else if(px!=py){
                    //变成同一类
                    //距离：在%3 的意义下：d[x] + ? = d[y] 
                    p[px] = py;
                    d[px] = d[y] -d[x];
                }
            }else{ // x吃y x的距离比y多1
                if(p[x] == p[y] && (d[x] - d[y]-1)%3) res++;
                else if(p[x] != p[y]){
                    p[px] = py;
                    //距离：dx + ? - dy = 1
                    d[px] = d[y] + 1 - d[x];
                }
            }
        }
    }
    printf("%d\n",res);
    return 0;
}