/*
Author: CagurZhan
Description: 给定一个邻接矩阵，求岛屿数量——求连通块数量
*/
#include <iostream>
#include <vector>
using namespace std;

int direction[2][4] = {
    {-1,0,1,0},
    {0,1,0,-1}
};

// dfs版本
void dfs(int x, int y , vector<vector<char>>&grid, vector<vector<bool>>&isVisited){

    for(int i=0;i<4;i++){
        int newX = x + direction[0][i];
        int newY = y + direction[1][i];
        if(newX < 0 || newX >= grid.size() || newY <0 || newY >= grid[0].size()) continue;

        if(!isVisited[newX][newY] && grid[newX][newY] == '1'){
            isVisited[newX][newY] = true;
            dfs(newX,newY,grid,isVisited);
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    // 掌握二维向量的初始化方法
    vector<vector<bool>> isVisited(n,vector<bool>(m,0));

    int res = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == '1' && !isVisited[i][j]){
                isVisited[i][j] = true;
                dfs(i,j,grid,isVisited);
                res++;
            }
        }
    }
    return res;
    
}

// BFS版本



int main(){
    
    return 0;
}