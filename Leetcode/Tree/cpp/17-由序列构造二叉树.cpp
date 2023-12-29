/*
Author: CagurZhan
Description: 由中序序列和后序序列构造二叉树
*/
#include <iostream>
#include "TreeNode.h"
using namespace std;

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

}

// 先写一个容易理解的版本，帮助理解算法的步骤
TreeNode* dfs(vector<int>&inorder, vector<int>&postorder){   

    // 第一步，空结点
    if(postorder.size() == 0) return nullptr;

    // 第二步，找后序序列的最后一个结点
    int postLast = postorder.back();
    TreeNode* node = new TreeNode(postLast);    

    // 判断是否为叶子结点
    if(postorder.size() == 1) return node;

    // 第三步，根据后序序列的最后一个结点，找到中序序列的分割点
    int inOrderMid;
    for(inOrderMid=0;inOrderMid < inorder.size();inOrderMid++){
        if(inorder[inOrderMid] == postLast) break;
    }

    // 第四步，切割中序，左闭右开
    vector<int>leftInorder(inorder.begin(), inorder.begin() + inOrderMid);
    vector<int>rightInorder(inorder.begin()+inOrderMid + 1, inorder.end());

    // 抛弃后序的最后
    postorder.pop_back();

    // 第五步，切割后序
    vector<int>leftPost(postorder.begin(),postorder.begin() + leftInorder.size());
    vector<int>rightPost(postorder.begin()+leftInorder.size(),postorder.end());

    // 第六步，递归处理
    node->left = dfs(leftInorder,leftPost);
    node->right = dfs(rightInorder,rightPost);

    return node;
}   

// 索引版本，不需要重复定义vector
// 左闭右开
TreeNode* dfsBuildTree(vector<int>&inorder, int ist, int ied,vector<int>&postorder
, int pst, int ped){

    if(pst == ped) return nullptr;

    // 第一步，后序结点最后一个元素
    TreeNode* root = new TreeNode(postorder[ped-1]);
    // 叶子结点
    if(ped - pst == 1) return root;

    // 第二步，找中序结点的中间元素
    int iMid;
    for(iMid= ist; iMid!=ied; iMid++)
        if(inorder[iMid] == root->val) break;
    
    // 第三步，切割中序序列
    int iLeftSt = ist;
    int iLeftEd = iMid;
    int iRightSt = iMid + 1;
    int iRightEd = ied;

    // 第四步，切割后序序列
    int pLeftSt = pst;
    int pLeftEd = pst + iMid - ist;
    int pRightSt = pLeftEd;
    int pRightEd = ped -1; // 排除最后一个元素

    // 第五步，递归处理
    root->left = dfsBuildTree(inorder,iLeftSt,iLeftEd,postorder,pLeftSt,pLeftEd);
    root->right = dfsBuildTree(inorder,iRightSt,iRightEd, postorder,pRightSt,pRightEd);

    return root;

}

// 凝练写法
TreeNode* dfsBuildTree(vector<int>&inorder, int ist, int ied,vector<int>&postorder
, int pst, int ped){

    if(pst == ped) return nullptr;
    TreeNode* root = new TreeNode(postorder[ped-1]);
    int iMid;
    for(iMid= ist; iMid!=ied; iMid++)
        if(inorder[iMid] == root->val) break;
    root->left = dfsBuildTree(inorder,ist,iMid,postorder,pst,pst + iMid - ist);
    root->right = dfsBuildTree(inorder,iMid + 1,ied, postorder,pst + iMid - ist,ped -1);
    
    return root;
}

// 由前序序列和中序序列构造二叉树
TreeNode* dfsBuildTreeByInorder(vector<int>&inorder, int ist, int ied,vector<int>& preorder, int pst, int ped){
    if(pst == ped) return nullptr;
    TreeNode *root = new TreeNode(preorder[pst]);
    int iMid;
    for(iMid=ist;iMid!=ied;iMid++)
        if(inorder[iMid] == root->val) break;
    root->left = dfsBuildTree(inorder,ist,iMid,preorder,pst+1,pst+1+iMid - ist);
    root->right = dfsBuildTree(inorder,iMid+1,ied,preorder,pst+1+iMid-ist,ped);
    return root;
}


int main(){
    
    return 0;
}