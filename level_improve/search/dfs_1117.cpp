/*
title: 单词接龙
from: acwing 1117
Tag: dfs
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 21;
string word[N];
int n;
int ans;
//求两个单词重叠部分的最小值
int g[N][N];
int cnt[N];
void dfs(string dragon, int last){

    ans = max((int)dragon.size(),ans);
     
    cnt[last]++;

    for(int i =0;i<n;i++)
        if(g[last][i] && cnt[i] < 2){
            //可以接上
            dfs(dragon+word[i].substr(g[last][i]),i);//从重合部分向后加
        }

    cnt[last]--;
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> word[i];
    char start;
    cin >> start;
    
    //初始化，建图
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            {
                string a = word[i];
                string b = word[j];
                //a的后缀和b的前缀相等
                //从小到大重合长度
                for(int k=1;k<min(a.size(),b.size());k++){
                    if(a.substr(a.size()-k,k) == b.substr(0,k)){
                        g[i][j] = k;
                        break;
                    }
                }
            }
    for(int i=0;i<n;i++){
        if(word[i][0] == start)
            dfs(word[i],i); // 记录一下结尾的单词编号
    }
    cout << ans << endl;
    return 0;
}