#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 10;
struct Plane{
    int t,l,d;
}p[N];
bool st[N];
int n;

bool dfs(int u , int last){
    if(u == n) return true;
    
    for(int i=0;i<n;i++){
        int t = p[i].t , l = p[i].l, d= p[i].d;
        if(!st[i] && t+d >=last){
            st[i] = true;
            if(dfs(u+1,max(t,last) + l)) return true;
            st[i] = false;
        }
    }
}

int main(){

    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            int t,l,d;
            scanf("%d%d%d",&t,&l,&d);
            p[i] = {t,l,d};
        }
        memset(st,0,sizeof st);
        if(dfs(0,0)) puts("YES");
        else puts("NO");
        
    }

    return 0;
}