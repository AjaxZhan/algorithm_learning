#include <iostream>
#include <cstdio>
using namespace std;
class Solution {
public:
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

