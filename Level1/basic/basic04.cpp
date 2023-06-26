/*
并查集
食物链，Acwing240
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 50010;
int n,m;
int p[N],d[N]; // d表示距离

int find(int x){
    if(p[x]!=x){
        //先记录根节点的位置
        int t = find(p[x]);
        //更新x到根节点的距离
        d[x]+=d[p[x]];
        //将x指向根节点
        p[x] = t;
    }
    return p[x];
}

int main(){
    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;i++) p[i] = i; // 并查集初始化 

    int res = 0;
    while(m--){
        int t,x,y; // t为种类
        scanf("%d%d%d",&t,&x,&y);

        if(x > n || y > n) res++;
        else{
            int px = find(x),py = find(y);
            if(t == 1){ // 询问是否同类
                if(px == py && (d[x]-d[y])%3!=0) res++;  // 同一棵树情况下，不是同类的话
                else if(px!=py){ // 不同树的情况下，xy应该同类
                    p[px] = p[y]; // 先做融合操作，x指向y，y作为父亲
                    d[px] = d[y] - d[x]; //更新距离
                }
            }else{
                if(px == py &&  (d[x] - d[y]-1)%3 != 0) res ++; // 同一棵树,不满足x吃y
                else if(px!=py){
                    p[px] = p[y];
                    //x应该吃y
                    d[px] = d[y] + 1 - d[x];
                }
            }
        }
    }
    printf("%d\n",res);
    return 0;
}