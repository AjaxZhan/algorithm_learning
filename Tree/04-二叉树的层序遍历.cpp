/*
Author: CagurZhan
Description: 二叉树的层序遍历
*/
#include <iostream>
#include <queue>
#include <vector>
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

void levelOrderTraversal(TreeNode *root,vector<int>res){
    if(root == nullptr) return ;
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode * tmp = q.front();
        q.pop();
        res.push_back(tmp->val);
        if(tmp->left!=nullptr) q.push(tmp->left);
        if(tmp->right!=nullptr) q.push(tmp->right);
    }
    
}

// LeetCode102 将二叉树层序遍历输出为二维数组
void levelOrderTraversal2(TreeNode *root,vector<vector<int>>&res){
    if(root == nullptr) return ;
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){

        int size = q.size();
        vector<int>inner;

        for(int i=0;i<size;i++){    
            TreeNode * tmp = q.front();
            q.pop();
            inner.push_back(tmp->val);
            if(tmp->left!=nullptr) q.push(tmp->left);
            if(tmp->right!=nullptr) q.push(tmp->right);
        }

        res.push_back(inner);

    }
    
}



int main(){
    
    return 0;
}