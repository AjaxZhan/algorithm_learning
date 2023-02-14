/*
title:蓝桥杯备赛
from:AcWing 803. 区间合并
Tag:区间合并 模板 贪心
拓展建议：贪心的区间问题
O(NlogN)
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int,int> PII;
const int N = 100010;
vector<PII>segs;

void merge_segs(vector<PII>&segs){
    vector<PII>res;
    //按照左端点进行排序
    sort(segs.begin(),segs.end());
    //维护当前区间
    int st = -2e9,ed=-2e9;
    for(auto seg : segs){
        if(ed < seg.first){
            if(ed!=-2e9) res.push_back({st,ed});
            st = seg.first;
            ed = seg.second;
        }else ed = max(ed,seg.second);
    }

    if(st!=-2e9) res.push_back({st,ed});

    segs = res;
}

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int l,r;
        cin >> l >> r;
        segs.push_back({l,r});
    }
    merge_segs(segs);
    cout << segs.size() << endl;

    return 0;
}