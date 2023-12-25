/*
Author: CagurZhan
Description: 一棵树是否存在子树和另外一棵树相等
*/
#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
};

bool isSubTree(TreeNode*root,TreeNode*subRoot){
    if(root == nullptr) return false;

    if(compare(root,subRoot)) return true;

    return isSubTree(root->left,subRoot) || isSubTree(root->right,subRoot);

}

// 比较两棵树是否相等
bool compare(TreeNode* left, TreeNode* right){
        // 三种情况：左边空，右边非空；左边非空，右边空；左右都空；左右都非空
        if(left == nullptr && right!= nullptr) return false;
        else if(left!=nullptr && right == nullptr) return false;
        else if(left == nullptr && right == nullptr) return true ;
        else if(left->val != right->val) return false;

        // 单层逻辑：左右都非空，数值相同
        bool inner = compare(left->left,right->left);
        bool outer = compare(left->right,right->right);

        return inner && outer;

}

int main(){
    
    return 0;
}