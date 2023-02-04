/*
状态压缩DP
Hamilton路径

*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 20,M = 1<< N;
int n;
int w[N][N];
int f[M][N];
int main(){
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> w[i][j];
    
    //初始化，从0走到0,从二进制来讲，就是0000000...1 和0
    memset(f,0x3f,sizeof f);
    f[1][0] = 0;
    for(int i=0;i<1 << n;i++)
        for(int j=0;j<n;j++)
            //i的第j位必须是1， 保证i中有j这个点
            if(i >> j & 1)
                for(int k=0;k<n;k++)
                    //i除去j这个点，必须包含k
                    if((i-(1 <<j) >> k &1))
                        f[i][j] = min(f[i][j],f[i-(1<<j)][k] + w[k][j]);
    
    //所有点都走完了,全部都是1
    cout << f[(1<<n) -1][n-1] <<endl;
    return 0;
}