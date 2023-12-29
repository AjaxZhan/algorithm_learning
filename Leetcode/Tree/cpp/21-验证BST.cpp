/*
Author: CagurZhan
Description: 
*/
#include <iostream>
#include "TreeNode.h"
using namespace std;

bool isValidBST(TreeNode* root) {
    
    vector<int>res;
    dfs(root,res);
    for(int i=0;i<res.size()-1;i++)
        if(res[i] >= res[i+1]) return false; // 必须小于等于，BST不能有相同元素！！！
    return true;
}

// 第一种写法，中序遍历，观察数组是否有顺序
void dfs(TreeNode * root,vector<int>&res){
    if(root == nullptr) return ;
    dfs(root->left,res);
    res.push_back(root->val);
    dfs(root->right,res);
}

bool isValidBST2(TreeNode* root){
    long long maxVal = LONG_LONG_MIN;
    return dfs2(root,maxVal);

}

// 第二种写法，递归判断
bool dfs2(TreeNode* root, long long& maxV){
    if(root == nullptr) return true;
    // 中序遍历
    bool left = dfs2(root->left,maxV);
    if(root->val > maxV ) maxV = root->val;
    else return false;
    bool right = dfs2(root->right,maxV);

    return left && right;
}

int main(){
    
    return 0;
}