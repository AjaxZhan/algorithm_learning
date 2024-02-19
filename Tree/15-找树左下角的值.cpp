/*
Author: CagurZhan
Description: 找到树最左下角的值
*/
#include <iostream>
#include "TreeNode.h"
using namespace std;

// BFS最简单
int findBottomLeftValue(TreeNode* root){
        queue<TreeNode*>q;
        q.push(root);
        int l = root->val;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* p = q.front();
                q.pop();
                if(i == 0){
                    l = p->val;
                }
                if(p->left!=nullptr) q.push(p->left);
                if(p->right!=nullptr) q.push(p->right);
            }
        }
        return l;

}

// DFS，记录深度，求解树的最大深度
int findBottomLeftValueByDfs(TreeNode* root){
    int res = 0;
    int MaxDepth = INT_MIN;
    dfs(root,1,MaxDepth,res);
    return res;
}
void dfs(TreeNode * root, int depth,int& maxDepth,int &res){    
    if(root->left == nullptr && root->right == nullptr){
        // 只需要保证先递归左边，即可保证最左
        if(depth > maxDepth ){
            maxDepth = depth;
            res = root->val;
        }
    }

    if(root->left!=nullptr) dfs(root->left,depth+1,maxDepth,res);
    if(root->right!=nullptr) dfs(root->right,depth+1,maxDepth,res);

}

int main(){
    
    return 0;
}