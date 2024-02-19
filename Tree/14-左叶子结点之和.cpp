/*
Author: CagurZhan
Description: 求解二叉树所有左叶子结点的权值之和
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};


// 返回其所有左右儿子结点之和
int leftChildSum(TreeNode*cur){
    if(cur == nullptr || (cur->left==nullptr && cur->right == nullptr))
        return 0;
    // 这里不能直接返回，必须先记录左子树的数量。
    // 否则根节点就能直接返回了
    int leftSum = 0;
    if(cur->left!=nullptr && cur->left->left == nullptr && cur->left->right == nullptr)
        leftSum =  cur->left->val;
    
    return leftSum + leftChildSum(cur->right);

}

int sumOfLeftLeaves(TreeNode* root) {
    
    return leftChildSum(root);

}

int main(){
    
    return 0;
}