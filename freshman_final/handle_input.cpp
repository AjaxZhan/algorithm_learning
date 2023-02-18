/*
title: C语言程序设计期末复习
from: 上学期小测一道模拟题
Tag: 输入输出 字符串 模拟
题目描述：
统计一段文本中出现次数最多的英文单词。
单词不区分大小写。单词和单词之间由一个或多个非字母字符隔开。
输入：一段文本，可能包含EOF
输出：该文本种出现最多的单词（全部转换为小写字母） 以及该单词出现的次数。
如果最多出现的单词有两个，输出字典序大的那个

思路：
一行一行读取，每次读取一个string。
对于每次读取的一行文本，进行预处理： 双指针算法， 筛出来每个单词，加入哈希表
加入哈希表前，可以先转换大小写
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
string line;
unordered_map<string,int>hashmap;
int main(){
    while(getline(cin,line)){
        int st = 0,ed=0;
        while(st < line.size()){
            while(!isalpha(line[st])) st++,ed= st;
            while(isalpha(line[ed])) ed++;
            string temp = line.substr(st,ed-st);
            for(int j=0;j<temp.size();j++){
                if(temp[j]>='A' && temp[j]<='Z') temp[j] +=32;
            }
            hashmap[temp] +=1;
            st = ed;
        }
    }
    string maxstr=  "";
    int maxcount = -1;
    for(auto s : hashmap){
        if(maxcount < s.second){
            string temp = s.first;
            maxstr = s.first;
            maxcount = s.second;
        }else if(maxcount == s.second){
            string temp = s.first;
            if(temp > maxstr)
                maxstr = s.first;
            maxcount = s.second;
        }
    }
    cout << maxstr << " " << maxcount<<endl;
    return 0;
}