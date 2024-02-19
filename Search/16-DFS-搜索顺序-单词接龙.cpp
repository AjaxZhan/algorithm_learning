/*
title: 单词接龙
Tag: DFS
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 21;
int n;
string word[N];
int g[N][N]; // 存储两个单词重叠部分的长度的最小值
int used[N];
int ans;
void dfs(string total, int last){
    ans = max(ans,(int)total.size());
    used[last]++;
    for(int i=0;i<n;i++){
        if(g[last][i] && used[i] < 2){
            dfs(total + word[i].substr(g[last][i]),i);
        }
    }
    used[last]--;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> word[i];
    }
    char start;
    cin >> start;
    
    // 预处理重叠长度
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            string a = word[i], b = word[j];
            for(int k=1;k<min(a.size(),b.size());k++){
                if(a.substr(a.size()-k) == b.substr(0,k)){
                    g[i][j] = k;
                    break;
                }
            }
        }
    // DFS
    for(int i=0;i<n;i++)
        if(word[i][0] == start)
            dfs(word[i],i); 

    cout << ans << endl;

    return 0;   
}