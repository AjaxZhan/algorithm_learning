/*
贪心算法
区间覆盖 Acwing907
Desc：给N个区间和一个询问区间，输出能够覆盖当前区间的最小区间数量。不能输出-1.
贪心思路：
    1. 将所有区间按照左端点从小到大排序。
    2. 从前往后枚举每个区间，{在所有能覆盖所需左端点的区间中，选择右端点最大的一个区间}
    3. 将当前区间的左端点，更新为右端点的最大值
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100010;
const int INF = 0x3f3f3f3f;
int st,ed,n;
struct Range{
    int l,r;
    bool operator<(const Range &W)const{
        return l  < W.l;
    }
}range[N];

int main(){
    scanf("%d%d",&st,&ed);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        range[i] = {a,b};
    }

    sort(range,range+n);
    
    bool flag = false; // 判断是否覆盖成功

    int res = 0; // 覆盖的区间数量
    
    //双指针算法
    for(int i=0;i<n;i++){
        
        int j = i, r=-INF;
        //如果说当前区间左端点在st的左边，表示可能覆盖
        while(j < n && range[j].l <=st){
            r=max(r,range[j].r); // 更新这些可能覆盖的区间的右端点最大值
            j++;
        }
        
        //排除没有交集的区间
        if(r < st){
            res = -1;
            break;
        }

        //选择右端点最大的区间后，答案+1
        res ++; 
        
        //判断是否覆盖完毕
        if(r >=ed){
            flag = true;
            break;
        }
        //更新st，迭代
        st = r;
        i = j-1;
    }
    if(flag) cout << res << endl;
    else cout << -1 << endl;
    return 0;
}