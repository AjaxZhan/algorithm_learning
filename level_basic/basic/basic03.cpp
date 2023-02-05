/*
BFS
八数码问题
思路：将问题转换为BFS，难点：状态表示，需要从二维转换到一维
*/
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

int bfs(string start){

    //目标状态
    string ed = "12345678x";

    //定义状态队列 和 dist数组，用哈希表存储
    queue<string>q;
    unordered_map<string,int>dist;

    //初始化
    q.push(start);
    dist[start] = 0;

    //偏移量
    int dx[4] = {-1,0,1,0},dy[4] = {0,1,0,-1};

    while(q.size()){
        auto t = q.front(); q.pop();
        int distance = dist[t];

        //枚举到了目标状态，返回distance

        if(t == ed) return distance;

        //状态转移
       
        int k = t.find('x');  //k表示的是x的一维下标
        int x = k/3, y = k%3; // 把x一维的x变成二维坐标

        for(int i=0;i<4;i++){
            int a = x + dx[i];
            int b = y + dy[i];

            if(a >=0 && a<3 && b>=0 && b<3){
                //将x与枚举到的量交换，从二维下标转到一维下标
                swap(t[k],t[a*3+b]);

                //如果是新状态，就入队
                if(!dist.count(t)) {
                    dist[t] = distance+1;
                    q.push(t);
                }
                //还原状态
                swap(t[k],t[a*3+b]); 
            }
        }
    }
    //无法转移到目标状态
    return -1;

}

int main(){
    string start;
    for(int i =0;i<9;i++){
        char c;
        cin >> c;
        start+=c;
    }

    cout << bfs(start) << endl;
    
    return 0;
}