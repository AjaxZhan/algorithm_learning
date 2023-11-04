/*
树形DP
没有上司的舞会 Acwing285.
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 6060;
int n;
int happy[N];
//存储状态
int f[N][2];
//是否存在父节点
bool has_father[N];
//邻接表来存储树
int h[N],e[N],ne[N],idx;
void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
void dfs(int u){
    //选择u
    f[u][1] = happy[u];
    
    for(int i=h[u];i!=-1;i=ne[i]){
        int j = e[i];
        dfs(j);
        f[u][0] +=max(f[j][0],f[j][1]);
        f[u][1] +=f[j][0];
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&happy[i]);
    memset(h,-1,sizeof h);

    for(int i=0;i<n-1;i++){ // n-1条边
        int a,b; // b是根节点
        scanf("%d%d",&a,&b);
        has_father[a] = true;
        add(b,a);
    }    
    
    //找到根节点
    int root = 1;
    while(has_father[root]) root++;
    dfs(root);
    printf("%d\n",max(f[root][0],f[root][1]));
    return 0;
}