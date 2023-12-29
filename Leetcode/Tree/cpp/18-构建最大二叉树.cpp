/*
Author: CagurZhan
Description: 构建最大二叉树
*/
#include <iostream>
#include "TreeNode.h"
using namespace std;

// 左闭右开
TreeNode* dfsBuildMaxTree(vector<int>&nums, int st, int ed){

    if(st == ed) return nullptr;

    // find max element
    int maxI = st;
    for(int i=st;i<ed;i++)
        if(nums[i] > nums[maxI])
            maxI = i;

    TreeNode * root = new TreeNode(nums[maxI]);

    root->left = dfsBuildMaxTree(nums,st,maxI);
    root->right = dfsBuildMaxTree(nums, maxI+1,ed);
    return root;
}

int main(){
    
    return 0;
}