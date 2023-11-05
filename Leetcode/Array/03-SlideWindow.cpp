/*
Author: CagurZhan
Description: 滑动窗口，给定一个数组，求满足其总和>=target的长度最小的连续子数组。
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// 滑动窗口思想：本质上还是双指针算法。
// 不过for循环遍历的指针是区间的结束位置，而不是开始位置，否则就陷入暴力了。
// 起始位置：如果当前窗口位置>s，就要向前移动。

class Solution {
public:
    // 209: 长度最小的子数组
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT32_MAX; // 结果，数组长度
        int len = 0 ; // 窗口长度
        int st = 0; // 窗口首部指针
        int sum = 0; // 窗口内部和
        for(int j=0;j<nums.size();j++){
            sum+=nums[j];
            while(sum>=target){
                len = j - st + 1;
                res = len < res ? len : res;
                sum -= nums[st++];
            }
        }
        return res==INT32_MAX ? 0 : res;
    }

    // 扩展题1: [Hard]76.最小覆盖子串
    // 扩展题2: [Mid]904.水果成篮
    int totalFruit(vector<int>& fruits) {
        // 我的思路：感觉就是把滑动窗口换了个条件。就是不能重复罢了。
        // 滑动窗口要求最短，这个要求最长
        int res = 0; // 结果，数组长度
        int len = 0 ; // 窗口长度
        int st = 0; // 窗口首部指针
        unordered_map<int,int>hashmap; // 存储出现次数
        for(int j=0;j<fruits.size();j++){
            hashmap[fruits[j]]++;
            while(hashmap.size() > 2){
                auto it = hashmap.find(fruits[st]);
                --it->second;
                if(it->second == 0) hashmap.erase(it);
                ++st;
            }
            res = (j-st+1) > res ? (j-st+1) : res;
        }

        return res;
    }
};
int main(){
    
    return 0;
}