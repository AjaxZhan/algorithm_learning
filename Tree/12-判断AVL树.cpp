/*
Author: CagurZhan
Description: 判断一棵树是不是ALV树
*/
#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

// 返回-1表示非AVL树，否则返回树的高度
int getAVLDepth(TreeNode* root){
    if(root == nullptr) return 0;
    
    int left = getAVLDepth(root->left);
    int right = getAVLDepth(root->right);
    if(left == -1 || right == -1) return -1;
    if(abs(left-right) > 1) return -1;
    return 1 + max(left,right);
}

int main(){
    
    return 0;
}