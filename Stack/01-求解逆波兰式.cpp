#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/**
 * 逆波兰式: 
 *      逆波兰式：后缀表达式。
 *      例如：(1+2)*(3+4) 为中缀表达式，求其后序遍历，1 2 + 3 4 + * 这就是逆波兰式。
 *      后缀表达式从头到尾遍历即可计算出正确的结果。
 * 计算：
 *      遇到数字入栈，遇到表达式取出元素并计算，入栈。
 * 
 */
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long>st;
        for(auto &item : tokens){
            if(item == "+" || item == "-" || item == "*" || item == "/") {
                auto a = st.top();
                st.pop();
                auto b = st.top();
                st.pop();
                if(item == "+") st.push(a+b);
                else if(item == "-") st.push(b-a);// 注意出栈顺序是相反的
                else if(item == "*") st.push(a*b);
                else if(item == "/") st.push(b/a); // 注意出栈顺序是相反的
            }else{
                st.push(stoll(item));
            }
        }
        int res = st.top();
        st.pop();
        return res;
    }
};

int main(){


    return 0;
}