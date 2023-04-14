/*
题目：给定后序遍历和中序遍历，输出二叉树的层序遍历。
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
const int N = 40;
int post[N],inord[N]; // 后序遍历，中序遍历
unordered_map<int,int>pos,l,r; // 后序的节点对应中序的位置，左子树，右子树
int n;
//建树，参数：子树在中序遍历的区间 以及 子树在后序遍历的区间
int build(int il, int ir, int pl , int pr){
    int root = post[pr];
    int k = pos[root]; // 中序位置
    if(il < k )l[root] = build(il,k-1,pl,pl+k-il-1);
    if(k < ir) r[root] = build(k+1,ir,pl+k-il,pr-1);
    return root;
}
void bfs(int root){
    queue<int>q;
    q.push(root);
    while(q.size()){
        auto t = q.front();q.pop();
        cout << t << " ";
        if(l.count(t)) q.push(l[t]);
        if(r.count(t)) q.push(r[t]);
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> post[i];
    for (int i = 0; i < n; i ++ ){
        cin >> inord[i];
        pos[inord[i]] = i; // 通过点找下标
    }
    //建树
    int root = build(0,n-1,0,n-1);
    //宽搜
    bfs(root);
    
    
    return 0;
}