#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
    
    bool bfs(int i, vector< vector<int> >& graph, vector<int>& color){
        queue<int> myQueue;
        color[i] = 1;
        myQueue.push(i);
        while(!myQueue.empty()){
            int node = myQueue.front();
            myQueue.pop();
            for(int item : graph[node]){
                if(color[item] == 0){
                    myQueue.push(item);
                    color[item] = -color[node];
                }
                if(color[item] == color[node]){return false;}
            }
        }
        return true;
    }
    bool isBipartite(vector< vector<int> >& graph) {
        vector<int> color(graph.size(), 0);
        for(int i = 0;i < graph.size();i++){
            if(color[i] == 0 && !bfs(i, graph, color)){
                return false;
            }
        }
        return true;
    }
};