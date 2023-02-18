/*
title: 蓝桥杯复习
from: AcWing 95. 费解的开关
Tag: 递推 位运算
Code:

*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 6; // 多开一个：字符串有个\0
char g[N][N],backup[N][N]; // 备份数组，在枚举32种状态的时候需要复原。
//偏移量
int dx[5] = {-1,0,1,0,0};
int dy[5] = {0,1,0,-1,0};
void turn(int x,int y){
    //枚举偏移量，5个位置
    for(int i=0;i<5;i++){
        int a = x + dx[i];
        int b = y + dy[i];
        if(a <0 || a>=5 || b < 0 || b>=5) continue;
        g[a][b] ^=1; //利用0和1的ASCII码特点，只需要进行异或操作就可以实现两者的转换。
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        //读取棋盘，按行读取
        for(int i=0;i<5;i++) cin >> g[i];
        int res = 10; //记录最小步数，刚开始设置为>6
        //枚举所有选择，必须枚举第一行所有的状态
        for(int op= 0;op<32;op++){
            memcpy(backup, g, sizeof g); // 每一种状态做完，都要将g复原
            int step = 0; // 步数
            //这里是枚举，还不是对第一行进行判断，注意理解
            for(int i=0;i<5;i++){
                if(op >>i &1){ // 这里的1表示的是枚举的每一种状态
                    step++;
                    turn(0,i);
                }
            }
            //每一行判断，除了最后一行
            for(int i=0;i<4;i++)
                for(int j=0;j<5;j++)
                    if(g[i][j] == '0'){
                        step++;
                        turn(i+1,j);
                    }
            
            //对最后一行额外判断
            bool isdark = false;
            for(int j=0;j<5;j++)
                if(g[4][j] == '0'){
                    isdark = true;
                    break;
                }
            
            if(!isdark) res = min(res,step);
            memcpy(g,backup,sizeof g);
        }
        if(res >6) res = -1;
        cout << res << endl;

    }
    return 0;
}