/*
Author: CagurZhan
Description: 二叉树的递归遍历
*/
#include <iostream>
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

class Solution{
public:
    // 前序遍历
    void traversal(TreeNode *root,vector<int> &res){
        if(root != nullptr){
            res.push_back(root->val);
            traversal(root->left,res);
            traversal(root->right,res);
        }
    }
};

int main(){



    return 0;
}