/*
记忆化搜索
用递归的方式实现动态规划
滑雪 acwing901.
记忆化搜索优点：代码复杂度低，好写。
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 310;
int n,m;
int h[N][N];//高度
int f[N][N];//状态
//枚举偏移量
int dx[4] = {-1,0,1,0},dy[4]={0,1,0,-1};

//返回每一个状态的值
int dp(int x, int y){
    int &v = f[x][y]; //别名
    if(v!=-1) return f[x][y]; // 走过了
    v = 1;//最少也能走当前的格子
    //枚举偏移量
    for(int i=0;i<4;i++){
        int a = x + dx[i];
        int b = y + dy[i];
        if(a >=1 && a<=n && b>=1 && b<=m && h[a][b] < h[x][y] )
            v = max(v,dp(a,b)+1);
    }
    return v;

}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&h[i][j]);
    //初始化表示都没有走过
    memset(f,-1,sizeof f);
    
    int res =0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            res = max(res,dp(i,j));
    
    printf("%d\n",res);
    return 0;
}