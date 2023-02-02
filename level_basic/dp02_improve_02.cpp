/*
DP--完全背包问题
和01背包问题一样，可以直接删掉一维
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1010;
int n,m;
int v[N],w[N];
int f[N];

int main(){
    cin >> n >> m;
    for(int i =1 ;i<=n ; i++) cin >> v[i] >> w[i];
    for(int i=1;i<=n;i++)
        for(int j=v[i];j<=m;j++){
            // f[i][j] = f[i-1][j];
            //这里就没有01背包的问题了，不用从大到小开始枚举
            f[j] = max(f[j],f[j-v[i]]+w[i]);
        }

    cout << f[m] << endl;    
    return 0;
}
