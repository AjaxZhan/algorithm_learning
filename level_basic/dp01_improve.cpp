/*
01背包问题--一维度优化版本
注意：DP问题的优化是基于代码逻辑，与问题本身无关。
感觉就是对循环语句的理解。
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1010;

int n,m; //n所有物品个数，m为背包容量
int v[N],w[N];
// int f[N][N];
int f[N];

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> v[i] >> w[i];
    
    for(int i=1;i<=n;i++)
        // for(int j=0;j<=m;j++){
        for(int j=m;j>=v[i];j--){ // 从大到小枚举，保证max那一句话
                                  // 将条件移到循环内
            // f[i][j] = f[i-1][j];//由于右边先算出来，再更新左边，因此可以去掉。变成 f[j] = f[j];
            //那么就可以不用写这句话
            
            // if(j>=v[i]) f[i][j] = max(f[i][j],f[i-1][j-v[i]] + w[i]);
            // 这里j-v[i]<j，如果原来从大到小枚举，那必然是在第i层算出来，而不是i-1，要改成i-1
            // 则需要将循环条件改成 从小到大枚举
            f[j] = max(f[j],f[j-v[i]] + w[i]);
        }
    
    cout << f[m] << endl; //输出答案

    return 0;
}