/*
Author: CagurZhan
Description: 判断一棵二叉树是否是镜像对称的，这道题很考察逻辑分析的过程
*/
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

// 要比较的是左右两颗子树
bool compare(TreeNode*left, TreeNode *right){

    // 三种情况：左边空，右边非空；左边非空，右边空；左右都空；左右都非空
    if(left == nullptr && right!= nullptr) return false;
    else if(left!=nullptr && right == nullptr) return false;
    else if(left == nullptr && right == nullptr) return true;
    else if(left->val != right->val) return false;

    // 单层逻辑：左右都非空，数值相同
    bool inner = compare(left->right,right->left);
    bool outer = compare(left->left,right->right);

    return inner && outer;
}

bool isSymmetric(TreeNode*root){
    if(root == nullptr) return true;
    compare(root->left,root->right);
}

// 迭代写法

bool isSymmetric2(TreeNode*root){
    if(root== nullptr) return true;

    queue<TreeNode*>q;
    q.push(root->left);
    q.push(root->right);

    while(!q.empty()){
        TreeNode *p1 = q.front(); q.pop();
        TreeNode *p2 = q.front(); q.pop();
        if( p1!=nullptr && p2==nullptr) return false;
        else if(p1==nullptr && p2!=nullptr) return false;
        else if(p1 == nullptr && p2 == nullptr) return true;
        else if(p1->val!=p2->val) return false;

        q.push(p1->right);
        q.push(p2->left);
        
        q.push(p1->left);
        q.push(p2->right);

    }

    return true;
}

int main(){
    
    return 0;
}