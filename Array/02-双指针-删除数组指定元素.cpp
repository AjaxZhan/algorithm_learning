/*
Author: CagurZhan
Description: 删除数组中的元素
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    // 27: 使用双指针（快慢指针）删除数组中指定元素
    // fast指针找新数组的元素。赋值给slow指针指向的内容。
    // erase函数删除就是O(n)，即模拟erase函数实现。
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        for(auto &x:nums){
            if(x!=val){
                nums[slow++] = x;
            }
        }
        return slow;
    }
    
    //我的错误答案证明: 维护fast指针很麻烦，应该维护slow指针
    int wrongAns_27(vector<int>&nums,int val){
        int fast = 0;
        for(auto &item : nums) {
            if(fast < nums.size() && nums[fast] == val){
                fast++;
            }
            if(fast < nums.size()){
                item = nums[fast];
            }
            fast++;
        }
        return fast - nums.size();
    }

    // 26: 删除单调增的数组中的重复元素，返回长度。
    // 要求: 原地删除，空间复杂度O(1)
    int removeDuplicates(vector<int>& nums) {
        // 我的思路：扫两遍，第一遍将所有重复的值设置为min(nums)-1
        // 第二步，删除所有不合法的数。也是O(n)
        if(nums.size() == 1) return 1;
        
        int i = 0, j = 1;
        int m = nums[0] - 1; // 利用排序的特点，所有数字必然不等于这个数。 
        while(j < nums.size()){
            if(nums[i] == nums[j]){
                nums[j] = m;
                j++;
                continue;
            }else{
                i = j++;
            }
        }
        int slow = 0;
        for(auto &x:nums){
            if(x != m) nums[slow++] = x;
        }
        return slow;
    }

    // 283: 给定数组，将所有0移动到数组末尾
    void moveZeroes(vector<int>& nums) {
        // 第一个思路：用第一道题的算法，然后最后的元素都改成0即可。
        // 第二个思路：将第一个算法的步骤赋值操作改成交换操作。
        int slow = 0;
        for(auto &x:nums){
            if(x != 0) swap(x,nums[slow++]);
        }
    }

    // 844: 输入两个字符串，#表示退格，如果两个字符串是相等，返回真。
    bool backspaceCompare(string s, string t) {
        // 思路：堆栈！我真没想到。
        // 如果是普通字符，入栈，如果是#就出栈
        return help_844(s) == help_844(t);
    }

    string help_844(string str){
        string stk;
        for(auto &x : str){
            if(x != '#') stk.push_back(x);
            else{
                if(!stk.empty()) stk.pop_back();
            }
        }
        return stk;
    }

    // 977: 给定非递减顺序的数组nums，返回每个数字的平方和，要求也按照升序排序。
    // 要求: 时间复杂度O(n)
    vector<int> sortedSquares(vector<int>& nums) {
        // 从两头往中间扫，逆向加入数组
        vector<int>res(nums.size());
        int l = 0 ,r = nums.size()-1;
        int p = nums.size()-1;
        while(l<=r){
            if(-nums[l] >= nums[r]){
                res[p--] = (nums[l] * nums[l]);
                l++;
            }else{
                res[p--] = (nums[r] * nums[r]);
                r--;
            }
        }
        return res;

    }

    vector<int> stupidAns_977(vector<int>& nums) {
        // 我的思路：先扫一遍，指针停留到第一个>=0的数。
        // 以这个数为右指针，继续向右扫。这个数的上一个数为左指针，往回扫。比较。
        // 太蠢了，一堆特判
        vector<int>res;
        
        if(nums[0] >=0 ){
            // +
            for(auto &x:nums){
                res.push_back(x*x);
            }
            return res;
        }else if(nums[nums.size()-1] <=0){
            // -
            for(int i=nums.size()-1;i>=0;i--){
                res.push_back(nums[i]*nums[i]);
            }
            return res;
        }

        // 找分界点
        int r = 0;
        while(r<nums.size())
            if(nums[r]>=0) break;
            else r++;
        int l = r -1;
        // 双指针比较
        while(l >=0 && r <nums.size()){
            if(-nums[l] >= nums[r]) {
                res.push_back(nums[r] * nums[r]);
                r++;
            }else{
                res.push_back(nums[l]*nums[l]);
                l--;
            }
        }
        // 特判
        while(l>=0){
            res.push_back(nums[l] * nums[l]);
            l--;
        }
        while( r <=nums.size()-1){
            res.push_back(nums[r] * nums[r]);
            r++;
        }
        return res;
    }
    
};



int main(){
    return 0;
}