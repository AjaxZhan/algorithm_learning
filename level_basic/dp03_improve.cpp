/*
多重背包问题
经典优化，二进制优化，s--》logs
证明过程看笔记，感觉还用到了高考时候的数列知识 
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

//1000 * log2000 = 24000左右
const int N = 25000; // 这个数据范围，按照暴力解法就要挂掉了
const int M = 2010; //体积

int n,m;
int v[N],w[N];

int f[N]; // 因为新的cnt个，每个只能选一次，所以就是：logs个01背包问题，直接开一维就行了

int main(){
    cin >> n >> m;
    int cnt = 0; //表示所有新物品的编号
    for(int i=1;i<=n;i++){

        int a,b,s;
        cin >> a>> b >> s; //体积、价值、个数
        cnt++;

        int k = 1; // 把k个第i个物品打包
        while(k<=s){
            cnt++;
            v[cnt] = a*k;
            w[cnt] = b*k;
            s-=k;
            k*=2;
        }
        if(s > 0){
            cnt ++;
            v[cnt] = a*s;
            w[cnt] = b*s;
        }
    }
    n = cnt; // 将n更新成cnt，表示重新组合成的n

    //对cnt个背包，每个只能选1次，可以组合成原来想要的s
    for(int i=1;i<=n;i++)
        for(int j =m;j >=v[i];j--)
                f[j] = max(f[j],f[j-v[i]] + w[i]);

    cout << f[m] << endl;    
    return 0;
}