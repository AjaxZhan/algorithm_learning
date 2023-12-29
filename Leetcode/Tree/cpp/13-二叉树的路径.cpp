/*
Author: CagurZhan
Description: 输出一棵二叉树所有路径之和。
利用到了拷贝赋值做回溯，非常妙
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

vector<string> binaryTreePath(TreeNode* root){
    vector<string>res;
    string path = "";
    dfsPath(root,path,res);
    return res;

}

// 前序遍历
// 奥妙就在这里，path没有使用引用！
void dfsPath(TreeNode* cur, string path, vector<string>&res){

    path += to_string(cur->val);

    if(cur->left == nullptr && cur->right == nullptr){
        res.push_back(path);
        return ;
    }

    if(cur->left!=nullptr) dfsPath(cur->left,path+"->",res);
    if(cur->right!=nullptr) dfsPath(cur->right,path+"->",res);
}



int main(){

    
    return 0;
}