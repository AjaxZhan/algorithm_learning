/*
贪心
推公式：牛叠罗汉  相关题：国王的游戏
公式：w+s按照升序排序。 
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 50010;
int n;
//键值对方便排序
typedef pair<int,int> PII;
PII cow[N]; 

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int w,s;
        scanf("%d%d",&w,&s);
        cow[i] = {w+s,w};
    }
    //排序
    sort(cow,cow+n);

    int res = -2e9;
    int sum = 0; // 表示上面的牛的重量
    //迭代求一下危险系数的最大值
    for(int i=0;i<n;i++){
        res = max(res,sum- (cow[i].first - cow[i].second));
        sum+=cow[i].second;
    }
    printf("%d\n",res);
    return 0;
}