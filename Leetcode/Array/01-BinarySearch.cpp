#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:

    // 704: 简单二分查找
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

    // 34: 二分查找范围
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

    // 65: 浮点二分计算开方
    int mySqrt(int x) {
        // 浮点二分
        double l = 0 , r = x;
        while(r - l > 1e-8){
            double mid = (l+r) /2;
            if(mid * mid <= x ){
                l = mid;
            }else{
                r = mid;
            }
        }
        printf("%.7lf",l);
        // 如果是1，答案是0.999999，这时候应该加一个很小的数，让它可以取到1，否则会返回0
        return l+1e-6;
    }

    // 367: 判断某个数是否为完全平方数
    bool isPerfectSquare(int num) {
        double l= 1, r = num;
        while(r - l >= 1e-8){
            double mid = (l + r ) /2;
            if(mid * mid <=num) l = mid;
            else r = mid;
        }
        // 如果是整数，那么肯定会出现超出一丢丢或者低于一丢丢，只需要判断加上一个很小的数后是否是同一个整数即可。
        return (int)(l+1e-5) != (int)(l-1e-5);
    }


};