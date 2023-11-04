/*
Trie树
最大异或对
暴力思路，TLE
for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        res = max(res,a[i]^a[j]);
优化入口：选出a[j]
根据选不选01建立Trie树，每次尽量选与当前位不同。
Trie树除了存储字符串，还可以存储二进制数
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N  = 100010,M = 3000000;
int n;
int a[N];
int son[M][2]; //trie树
int idx;

void insert(int x){
    int p = 0;
    //枚举这个数字的每一个位数是0还是1 x >>i &1
    //从上往下走判断是否存在，不存在 就插入
    for(int i = 30;i>=0;i--){
        int &s = son[p][x >> i & 1];//引用，懒得写太多
        if(!s) s = ++idx;
        p = s; // 往下走 
    }
}
int query(int x){
    int res = 0,p = 0;
    for(int i=30;i>=0;i--){
        int s = x >>i &1;
        if(son[p][!s]){
            //尽量走不一样的分支
            res += 1 << i; // 每一位的贡献
            p = son[p][!s];
        }else p = son[p][s]; // 实在不行走相同分支，没贡献
    }
    return res;
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        insert(a[i]);
    }

    int res = 0;
    for(int i=0;i<n;i++) res = max(res,query(a[i]));


    
    cout << res << endl;

    return 0;
}