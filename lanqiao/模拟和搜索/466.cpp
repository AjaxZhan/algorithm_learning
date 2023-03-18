/*
title: 回文日期
from: acwing 466
Tag: 模拟 日期处理 枚举
Code:
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31}; // 平年
bool check(int date){
    //扣出年月日
    int year = date /10000; 
    int month = date % 10000 / 100;
    int day = date %100;
    
    //month
    if(!(month >=1 && month<=12)) return false;
    //day 分为二月份和不是二月份
    if((month!=2 && day>=1 && day <=days[month] )) return true;
    if(month ==2){
        int tmp =0;
        if(year%100 && year%4 == 0 || year%400 ==0)  tmp = 1;
        if(day>=1 && day<=days[month]+tmp) return true;
    }
    return false;

}
int main(){
    int date1,date2;
    cin >> date1 >> date2;
    
    int res = 0; //记录最终答案

    int date = 0;
    int tmp = 0;
    //枚举回文数
    for(int i=1000;i<=9999;i++){
        date = tmp = i;
        //扩充成为日期
        for(int j=0;j<4;j++) date = date*10 + tmp%10, tmp/=10;
        //是否范围内
        if(date >=date1 && date <=date2 &&check(date)) res++;
    }   
    cout << res << endl;

    return 0;
}