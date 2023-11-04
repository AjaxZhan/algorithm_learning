/*
基础算法
双指针算法--判断子序列
证明双指针算法的可行性：类似于调整法，如果存在一个匹配，那双指针算法的匹配一定在这个匹配的前面，由于切换不会影响后面的匹配。
因此若存在以这种匹配，则双指针算法可以找到这种匹配。
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 100010;
int n,m;
int a[N],b[N];
int main(){
    memset(a,0x3f,sizeof a);
    memset(b,0x3f,sizeof b);
    
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<m;i++) scanf("%d",&b[i]);
    //只移动第二个指针，第一个当且仅当匹配了才移动
	int i = 0;
	for(int j=0;j<m;j++){
		if(i < n && a[i] == b[j]) i++;
	}
	
    if(i == n) cout << "Yes" << endl;
    else cout << "No" << endl;
}