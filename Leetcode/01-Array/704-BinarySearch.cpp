#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 左右区间都是闭区间写法
        // left<=right  mid = right - 1
        // 这是我的第一道LeetCode题，以后代码尽量写得跟好懂一些，长没关系。
        int l = 0, r = nums.size()-1;
        while(l<=r){
            int mid = l + ((r - l) >> 1);
            if(target < nums[mid]){
                r = mid - 1;
            }else if(target > nums[mid]){
                l = mid + 1;
            }else{
                return mid;
            }
        }
        return -1;
    }
};