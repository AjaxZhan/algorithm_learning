/*
title: 字符变换
from: acwing 190
Tag: 双向BFS
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;
const int N = 6;
int n;
//初始化状态和终点状态
string A, B;
//规则字符串
string a[N],b[N];

int extend(queue<string>&q,unordered_map<string, int>&da, unordered_map<string, int>&db, string a[], string b[]){

    //每次必须扩展一层！！
    int d = da[q.front()];
    while(q.size() && da[q.front()] == d){ // 队头点的距离是否一样
        auto t = q.front();
        q.pop();

        //扩展
        //枚举规则
        for(int i=0;i<n;i++)
            //枚举子串
            for(int j=0;j<t.size();j++)
                if(t.substr(j,a[i].size()) == a[i]){ // 存在可替换子串
                    //前面部分 + 替换部分 + 后面部分
                    string r = t.substr(0,j) + b[i] + t.substr(j+a[i].size());
                    if(db.count(r)) return da[t] + db[r] + 1;
                    if(da.count(r)) continue; //搜过了
                    da[r] = da[t] +1;
                    q.push(r);
                }
    }
    return 11;
}
int bfs()
{
    //特判
    if(A ==B ) return 0;

    queue<string>qa,qb;
    unordered_map<string, int>da,db; // 距离
    //加入起点
    qa.push(A);
    qb.push(B);
    da[A] = db[B] = 0;
    //必须都不为空，否则不连通
    while(qa.size() && qb.size()){
        int t;
        //扩展成功会返回距离，否则返回 > 10 的数
        if(qa.size() < qb.size()) t= extend(qa,da,db,a,b);
        else t = extend(qb,db,da,b,a); // 规则要反过来
    
        if(t <=10 ) return t;
    }

    return -1; // 有一个队列为空，无解，不连通！

}

int main(){

    cin >> A >> B;
    //读取数据的套路
    while(cin >> a[n] >> b[n]) n++;
    
    int t = bfs();
    if(t == -1) puts("NO ANSWER!");
    else cout << t << endl;

    
    return 0;
}