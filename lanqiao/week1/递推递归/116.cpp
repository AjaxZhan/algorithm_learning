/*
title: 蓝桥杯复习 
from: acwing 116. 飞行员兄弟
Tag: 枚举 位运算
Code: 想法和费解的开关类似
扩展：208开关问题 -- 开关问题终极版，用高斯消元求解。
每个灯泡会被不止一个灯泡控制，因此没办法递推做。
观察开关数量：16个，状态最多2^16 = 65536，因此可以暴力枚举。
返回字典序最小的方案。枚举方式用二进制。按照该方案对所有灯泡进行操作，最后判断灯泡是否全亮。
复杂度：O(65536方案 * (16开关 * 7操作+16判断+16记录方案)) = 1kw复杂度
字典序最小？对于同样步数的方案，优先枚举字典序小方案。
优化：用二进制优化操作
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define x first
#define y second
typedef pair<int,int> PII;
const int N = 5;
char g[N][N],backup[N][N]; // 与费解的开关同理，需要一个备份数组
//通过二维坐标映射一维坐标
int get(int x, int y){
    return 4*x +y;
}

void turn_one(int x, int y){
    if(g[x][y] == '+') g[x][y] = '-';
    else g[x][y] = '+';
}

void turn_all(int x, int y){
    for(int i=0;i<4;i++){
        turn_one(x,i);
        turn_one(i,y);
    }
    turn_one(x,y); //中间的点被重复点亮
}


int main(){
    for(int i=0;i<4;i++) cin >> g[i];
    vector<PII>res;
    //枚举所有方案
    for(int op=0;op<1 << 16;op++){
        vector<PII>temp; // 临时方案
        memcpy(backup ,g,sizeof g); //备份

        //争对每一个方案，进行操作
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                if(op >> get(i,j) &1) {
                    temp.push_back({i,j});
                    turn_all(i,j);
                }
        
        //判断
        bool has_closed = false;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(g[i][j] == '+') has_closed = true;
                
            }
        }
        if(has_closed ==false ){
            if(res.empty() || res.size() > temp.size()) res = temp;
        }
        memcpy(g,backup,sizeof g);
    }
    cout << res.size() << endl;
    for(auto xp : res) cout << xp.x + 1 << " " << xp.y +1 << endl; 
    return 0;
}