/*
基础算法与数据结构
栈 经典题
中缀表达式求值
*/
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

//存储运算符和数字
stack<int>num;
stack<char>op;

//哈希表，存储运算符的优先级
unordered_map<char,int>cmp = {
    {'+',1},{'-',1},{'*',2},{'/',2}
};

//模拟一次算数操作
void eval(){
    int b = num.top();num.pop();
    int a = num.top();num.pop();
    char opr = op.top(); op.pop();
    
    int x;
    if(opr == '+') x = a+b;
    else if(opr == '-') x = a-b;
    else if(opr == '*') x = a*b;
    else x = a/b;

    num.push(x);
}

int main(){
    string str;
    cin >> str;
    
    for(int i=0;i<str.size();i++){
        auto c = str[i];
        //扣出数字
        if(isdigit(c)){
            int j = i, x = 0;
            while(j < str.size() && isdigit(str[j])){
                //不要忘记j++的迭代
                x = x*10 + str[j++] - '0';
            }
            num.push(x);
            i = j-1; // 别忘记更新i
        }else if (c == '('){
            //左括号直接加入
            op.push(c);
        }else if(c == ')'){
            //根据表达式的优先级，从右向左求值
            while(op.size() && op.top()!='(') eval(); 
            op.pop(); // 左括号弹出
        }else{
            //栈顶元素优先级大，先进行求值
            while(op.size() && cmp[op.top()] >= cmp[c]) eval();
            //压入新的运算符
            op.push(c);
        }
    }
    //处理栈内最后的低优先级的操作
    while(op.size()) eval();
    cout << num.top() << endl;
    

    return 0;
}