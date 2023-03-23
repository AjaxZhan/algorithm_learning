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
//表示A接到B，重叠部分长度最小值。（重叠部分越小，长度越大）
int g[N][N];
//每个单词最多被使用两次
int used[N];
int ans;

void dfs(string dragon, int last){
    ans = max((int)dragon.size(),ans);
    used[last]++;
    //枚举填哪个
    for(int i=0;i<n;i++){
        if(g[last][i] && used[i] < 2)
            dfs(dragon+word[i].substr(g[last][i]),i);
    }
    used[last]--;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin>> word[i];
    char start;
    cin >> start;
    //通过g建图，预处理出能走到哪些值
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            string a = word[i], b = word[j];
            //对于两个字符串A到B，从小到大枚举最短重合的数目
            for(int k=1;k<min(a.size(),b.size());k++){
                if(a.substr(a.size()-k,k) == b.substr(0,k)){
                    g[i][j] = k;
                    break;
                }
            }
        }
    }

    //以start开头
    for(int i=0;i<n;i++){
        if(word[i][0] == start ){
            dfs(word[i],i);
        }
    }
    cout << ans << endl;
    return 0;
}