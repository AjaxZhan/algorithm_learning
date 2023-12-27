/*
Author: CagurZhan
Description: 求完全二叉树结点个数(不利用普通的dfs和bfs，利用完全二叉树的性质)
*/
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

// 对于完全二叉树，其子树一定由满二叉树组成。
// 则我们可以利用满二叉树的性质，在O(1)时间内求出满二叉树的结点个数。
// 性质：在完全二叉树的前提下，满二叉树的左右递归深度相同，而题目保证输入为完全二叉树！
// 这道题用来理解递归也很不错。
int countNode(TreeNode* root){
    if(root == nullptr) return 0;
    // 判断是否是满二叉子树
    TreeNode* l = root->left;
    TreeNode* r = root->right;
    int lDepth = 0, rDepth = 0;
    while(l!=nullptr){
        lDepth+=1;
        l = l->left;
    }
    while(r!=nullptr){
        rDepth+=1;
        r = r->right;
    }
    if(lDepth == rDepth){
        return (2 << lDepth) -1;
    }

    // 递归处理
    int lCnt = countNode(root->left);
    int rCnt = countNode(root->right);
    return lCnt + rCnt + 1;

}

int main(){
    
    return 0;
}