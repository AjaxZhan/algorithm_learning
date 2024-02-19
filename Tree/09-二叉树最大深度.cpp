/*
Author: CagurZhan
Description: 求给定二叉树的最大深度
*/

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

// 方法1：层序遍历

int levelOrder(TreeNode* root){
    if(root == nullptr) return 0;
    
    queue<TreeNode*>q;
    q.push(root);

    int cnt = 0;
    while(!q.empty()){
        cnt ++ ;
        int size = q.size();

        for(int i=0;i<size;i++){
            TreeNode * p = q.front();
            q.pop();
            if(p->left!=nullptr) q.push(p->left);        
            if(p->right!=nullptr) q.push(p->right);
        }


    }

    return cnt;
    
}


// 方法2：后序遍历，很妙

int getDepth(TreeNode*root){
    

    if(root == nullptr) return 0;

    int l = getDepth(root->left);
    int r = getDepth(root->right);
    
    int depth = 1 + max(l,r);

    return depth;

}

// N叉树的深度
// 层序这里就不写了，之前写过了。


struct Node{
    int val;
    vector<Node*>children;
};

int getDepth(Node *root){
    if(root == nullptr) return 0;
    int maxDep = 0;
    for(auto& node : root->children){
        maxDep = max(maxDep,getDepth(node));
    }
    return maxDep + 1;

}

int main(){
    
    return 0;
}