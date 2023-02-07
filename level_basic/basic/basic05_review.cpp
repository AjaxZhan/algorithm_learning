/*
数据结构
Trie树
维护字符串集合，支持插入操作和询问字符串出现次数操作
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100010;
int son[N][26]; //存放每个点的所有儿子，每个节点最多向外连接26儿子
int cnt[N]; // 以当前点结尾的单词多少个
int idx;
char str[N];
//下标是0的点既是根节点又是空节点
void insert(char str[]){
    int p = 0;
    for(int i=0;str[i];i++){ // 遍历字符串 
        //映射字符串
        int u = str[i] - 'a';
        //son[p][u] 表示p节点的u儿子
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u]; // 继续向下走
    }
    cnt[p]++;
}
int query(char str[]){
    int p =0;
    for(int i=0;str[i];i++){
        int u  = str[i] - 'a';
        if(!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        char op[2];
        scanf("%d%s",&op,&str);
        if(op[0] == 'I') insert(str);
        else printf("%d\n",query(str));
    }
    return 0;
}