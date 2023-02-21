/*
title: 蓝桥杯复习
from: acwing 1497 树的遍历 PAT甲级真题1020
Tag: 树的遍历 递归 BFS 哈希表
Code: 笔试面试经典题
题目：给定二叉树的后序遍历和中序遍历，输出层序遍历。保证每个节点的值不一样。
（如果节点的值相同，二叉树就不唯一了）
性质：后序遍历，最后一个节点一定是根节点；中序遍历找到根节点，左边是左子树，右边是右子树。
发现左右子树长度后，确定后序遍历中左右子树的区间，递归处理。
找中序遍历中的位置：哈希表。

每个点只会处理一次：O(N)
*/
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
const int N = 40;
int n; // 节点数
int postorder[N];//后序遍历
int inorder[N]; // 中序遍历
unordered_map<int ,int>l,r,pos; // 存放每个点的左右儿子；在中序遍历内每个点对应的下标

//返回二叉树的根节点
int build(int il, int ir, int pl , int pr){
    int root = postorder[pr]; // 根节点是后序遍历的最后一个节点
    int k = pos[root]; // 哈希查找根节点在中序遍历中的下标
    if(il < k) l[root] = build(il,k-1,pl,pl + k -1 -il); // 根节点左儿子,pr-pl = k-1-il 长度相同
    if(ir > k) r[root] = build(k+1,ir,pl + k -il,pr - 1); // 根节点右边儿子
    return root;
}   

void bfs(int root){
    queue<int>q;
    q.push(root);
    while(q.size()){
        auto t = q.front();q.pop();
        cout << t << ' ';
        if(l.count(t)) q.push(l[t]);
        if(r.count(t)) q.push(r[t]);
    }
}   

int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> postorder[i];
    for(int i=0;i<n;i++){
        cin >> inorder[i];
        pos[inorder[i]] = i; //在哈希表中存储中存储中序遍历对应的下标
    }
    int root = build(0,n-1,0,n-1); // 构建二叉树；参数是中序遍历的区间，后续遍历的区间。
    
    bfs(root); // 层序遍历
    return 0;
}