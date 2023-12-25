/*
Author: CagurZhan
Description: N叉树的层序遍历
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    vector<TreeNode*> children;
    TreeNode(){

    }
    TreeNode(int val){
        this->val = val;
    } 
    TreeNode(int val,vector<TreeNode*> child){
        this->val = val;
        this->children = child;
    }
};

void levelOrderTraversal(TreeNode *root,vector<vector<int>>&res){
    
    if(root == nullptr) return;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        
        for(int i=0;i<size;i++){
            TreeNode * tmp = q.front();
            q.pop();
            level.push_back(tmp->val);
            for(auto & node : tmp->children){
                q.push(node);
            }
        }

        res.push_back(level);
    }
    
    
}

int main(){
    
    return 0;
}