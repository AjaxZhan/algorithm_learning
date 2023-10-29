/*
Author：Cagur
Content：
*/
#include <iostream>
#include <cstdio>
using namespace std;
class Solution {
public:
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
};
int main(){
    Solution solu;
    cout << solu.mySqrt(16) << endl;
}