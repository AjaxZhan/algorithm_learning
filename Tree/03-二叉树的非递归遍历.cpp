/*
Author: CagurZhan
Description: 二叉树的非递归遍历
*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    // 构造方法
    TreeNode(int val){
        this->val =  val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// 前序遍历的非递归实现：压栈顺序是父右左
void traversal(TreeNode *root,vector<int>&res){
    if(root==nullptr) return;

    stack<TreeNode*>stk;

    stk.push(root);
    while(!stk.empty()){
        TreeNode* top = stk.top();
        stk.pop();
        res.push_back(top->val);
        if(top->right!=nullptr) stk.push(top->right);
        if(top->left!=nullptr) stk.push(top->left);
    }
}

// 中序遍历
// 中序遍历一开始要遇到的是根节点，但是却要输出左子树，所以比较麻烦，需要通过指针来辅助。
// 指针一直向左走，入栈，直到空，才开始遍历
void inOrderTraversal(TreeNode *root,vector<int>&res){

    if(root == nullptr) return;

    stack<TreeNode*>stk;

    TreeNode *ptr = root;
    while(ptr!=nullptr || !stk.empty()){
        if(ptr!=nullptr){
            stk.push(ptr);
            ptr = ptr->left;
        }else{
            ptr = stk.top();
            stk.pop();
            res.push_back(ptr->val);
            ptr = ptr->right; 
        }
    }

}

// 后序遍历是左右中，思路比较巧妙
// reverse后是中右左
// 而先序遍历的代码时中左右，所以我们只需要修改下前序遍历的代码然后做一个reverse操作就可以啦
void postOrderTraversal(TreeNode *root,vector<int>&res){
    if(root == nullptr) return;

    stack<TreeNode*>stk;

    stk.push(root);
    while(!stk.empty()){
        TreeNode* tmp = stk.top();
        stk.pop();
        res.push_back(tmp->val);
        if(tmp->left!=nullptr) stk.push(tmp->left);
        if(tmp->right!=nullptr) stk.push(tmp->right);
    }

    reverse(res.begin(),res.end());
    
}

int main(){


    
    return 0;
}