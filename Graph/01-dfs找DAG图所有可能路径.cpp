/*
Author: CagurZhan
Description: 给定一个DAG图，找到从0号结点到n-1号结点的所有路径并输出
*/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>>allPaths;
    vector<int>path;
    path.push_back(0);
    dfs(graph,0,allPaths,path);
}

void dfs(vector<vector<int>>& graph, int cur,vector<vector<int>>&allPaths, vector<int>path){
    if(cur == graph.size() -1){
        allPaths.push_back(path);
        return ;
    }

    for(int i=0;i<graph[cur].size();i++){
        path.push_back(graph[cur][i]);
        dfs(graph, graph[cur][i],allPaths,path);
        path.pop_back();
    }

}