/*
Author: CagurZhan
Description: 二叉树的翻转
*/
#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

// 第一种写法：递归，先序遍历

TreeNode* invertTree(TreeNode* root){
    if(root == nullptr) return root;

    swap(root->left,root->right);
    invertTree(root->left);
    invertTree(root->right);

    return root;
}

// 非递归写法

TreeNode* invertTree(TreeNode* root){

    if(root == nullptr) return root;

    stack<TreeNode*> stk;
    stk.push(root);

    while(!stk.empty()){
        TreeNode * tmp = stk.top();
        stk.pop();

        swap(tmp->left,tmp->right);
        
        if(tmp->left != nullptr) stk.push(tmp->left);
        if(tmp->right != nullptr) stk.push(tmp->right);
    }
    return root;
}


int main(){
    
    return 0;
}