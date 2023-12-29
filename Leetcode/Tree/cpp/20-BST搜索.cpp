/*
Author: CagurZhan
Description: BST搜索
*/
#include <iostream>
#include "TreeNode.h"
using namespace std;

// 递归搜索
TreeNode* searchBST(TreeNode* root, int val) {
    if(root == nullptr) return nullptr;
    if(root->val == val) return root;
    else if(val < root->val) return searchBST(root->left,val);
    else return searchBST(root->right,val);
}

// BST结点的有序性从而能不需要stack和queue来进行迭代搜索
TreeNode* searBSTWithoutDfs(TreeNode* root, int val){
    while(root!= nullptr){
        if(root->val == val) return root;
        else if(root->val > val) root = root->left;
        else root = root->right;
    }
    return root;
}





int main(){
    
    return 0;
}