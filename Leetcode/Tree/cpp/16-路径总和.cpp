/*
Author: CagurZhan
Description: 判断二叉树中是否存在根节点到叶子结点的路径和等于给定值
*/
#include <iostream>
#include "TreeNode.h"
using namespace std;

bool hasPathSum(TreeNode* root, int targetSum){

    bool flag = false;
    dfs(root,targetSum,0,flag);
    return flag;

}

void dfs(TreeNode * root, int& targetSum, int sum, bool &flag){

    if(flag == true) return ;
    if(root == nullptr) return;

    if(root->left == nullptr && root->right == nullptr){
        if(sum + root->val == targetSum){
            flag = true;
        }
    }

    if(root->left != nullptr) dfs(root->left,targetSum,sum+root->val, flag);
    if(root->right != nullptr) dfs(root->right,targetSum,sum+root->val,flag);

}

int main(){
    
    return 0;
}