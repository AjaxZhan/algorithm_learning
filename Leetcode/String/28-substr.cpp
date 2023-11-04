#include <iostream>
#include <cstdio>
using namespace std;
/**
 * KMP算法解决的问题：
 *      匹配文本串和模式串。
 *      是K M P 三位大佬一起发的paper。
 *      O(m+n)，扫一遍两个串而已。
 * KMP算法理论：
 *      直观来说，根据next数组，将模式串的指针移动到指定位置继续匹配。
 *      最长相等前后缀：如aabaaf，aa这里就是出现过了。
 *      前缀：包含首字母，不包含尾字母的所有子串。
 *          这里就是a aa aab aaba aabaa
 *      后缀：只包含尾字母，不包含首字母。
 *          这里就是f af aaf baaf abaaf
 *      最长相等前后缀：
 *          串      长度
 *          a       0
 *          aa      1   
 *          aab     0
 *          aaba    1
 *          aabaa   2
 *          aabaaf  0
 *      这个就是这个模式串的前缀表：0 1 0 1 2 0
 *      使用前缀表进行匹配：
 *          例如，文本串是aabaabaaf 模式串是aabaaf
 *          匹配到f不匹配，就要跳到“2”的索引，也就是b的位置。
 *       这个前缀表也可以叫做next数组。
 */


class Solution {
public:
    int strStr(string haystack, string needle) {
        // 特判
        if(needle.size() == 0) return 0;
        // 获取next数组
        int next[needle.size()];
        getNext(next,needle);
        // 开始匹配
        int j = -1;
        for(int i=0;i<haystack.size();i++) {
            while(j>=0 && haystack[i]!=needle[j+1]){
                j = next[j];
            }
            if(haystack[i]== needle[j+1]){
                j++;
            }
            // 找到
            if(j == needle.size()-1){
                return i - needle.size() + 1;
            }
        }
        return -1;
    }
    
    // 构建next数组
    void getNext(int *next, const string &s) {
        // 用j+1 去和i比较
        // j同时维护着最长公共前后缀的长度
        int j = -1;
        next[0] = j;
        for(int i=1;i<s.size();i++) {
            while(j >=0 && s[i] != s[j+1]){
                j = next[j];
            }
            if(s[i] == s[j+1]){
                j++;
            }
            next[i] = j;
        }
    }
};
int main(){
    
    return 0;
}