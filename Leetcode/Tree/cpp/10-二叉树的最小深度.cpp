/*
Author: CagurZhan
Description: 求二叉树的最小深度
*/
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

// 这道题BFS很好写

int levelOrderTraversal2(TreeNode *root){
    if(root == nullptr) return 0 ;
    queue<TreeNode*> q;
    q.push(root);
    int res = 0;
    while(!q.empty()){
        res++;
        int size = q.size();
        for(int i=0;i<size;i++){    
            TreeNode * tmp = q.front();
            q.pop();
            if(tmp->left == nullptr && tmp->right == nullptr) return res;
            if(tmp->left!=nullptr) q.push(tmp->left);
            if(tmp->right!=nullptr) q.push(tmp->right);
        }
    }
    return res;
}

// DFS需要注意下
// 因为需要左右儿子都为空，才算是最小。如果直接将求max的代码改成min，如果左子树为空，就会认为是最小值。
// 所以同样也需要分类讨论
int dfs(TreeNode *root){
    if(root == nullptr) return 0;

    int l = dfs(root->left);
    int r = dfs(root->right);

    if(root->left==nullptr && root->right!=nullptr) return 1 + r;
    else if(root->left!=nullptr && root->right == nullptr) return 1+l;
    else if(root->left== nullptr && root->right == nullptr) return 1;
    return 1 + min(l,r);
}

int main(){
    
    return 0;
}