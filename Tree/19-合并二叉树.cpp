/*
Author: CagurZhan
Description: 合并二叉树
*/
#include <iostream>
#include "TreeNode.h"
using namespace std;

TreeNode* mergeTree(TreeNode* t1, TreeNode* t2){
    if(t1 == nullptr) return t2;
    if(t2 == nullptr) return t1;

    t1->val +=t2->val;
    // 因为需要修改结构，所以需要赋值语句
    t1->left = (t1->left,t2->left);
    t1->right = (t1->right,t2->right);

    return t1;
}

int main(){
    
    return 0;
}