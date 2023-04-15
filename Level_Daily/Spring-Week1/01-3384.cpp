/*
给定一个先序遍历的字符串，建立一个二叉树并输出中序遍历。
*/
#include <iostream>
using namespace std;
string tree;
int i;
void dfs(){
    //空节点返回
    if(tree[i] == '#'){
        i++;
        return;
    }
    char root = tree[i++];
    dfs();//递归左子树
    cout << root << ' ';
    dfs();//递归右子树
}
int main(){
    cin >> tree;
    dfs();
    return 0;
}