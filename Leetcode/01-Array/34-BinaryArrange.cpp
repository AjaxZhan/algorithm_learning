#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // 注意边界情况，否则编译错误。
        if(nums.empty()){
            return vector<int>{-1,-1};
        }
        // 1 2 3 3 3 4 5 6
        // 寻找左边界：一直向左找，改变r。
        // 改变谁，谁是mid。其它那个用+1/-1。
        // 如果是left不用 +1
        int l = 0,r = nums.size()-1;
        while(l < r){
            int mid = l + r >> 1;
            if(target <= nums[mid]) r = mid;
            else l = mid +1;
        }
        // 找不到
        if(nums[l]!=target) return vector<int>{-1,-1};
        
        // 寻找右边界：一直向右找，改变l
        int tmp = l;
        l = 0,r = nums.size()-1;
        while(l < r){
            int mid = l + r +1 >> 1;
            if(target>=nums[mid]) l = mid;
            else r = mid - 1;
        }
        return vector<int>{tmp,l};
    }
};