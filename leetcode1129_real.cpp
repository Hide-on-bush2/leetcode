#include<cmath>
#include<queue>
#include<utility>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    const int BLUE = 0;
    const int RED = 1;
    vector<int> shortestAlternatingPaths(int n, vector< vector<int> >& red_edges, vector< vector<int> >& blue_edges) {
        vector< vector< pair<int, int> > > G(n);//记录结点的出度和边的颜色。
        for(auto e : red_edges){G[e[0]].push_back(make_pair(e[1], RED));}
        for(auto e : blue_edges){G[e[0]].push_back(make_pair(e[1], BLUE));}
        vector< pair<int, int> > cost(n, make_pair(-1, -1));//first是红色边的路程花费，second是蓝色边的路程花费。
        queue< pair<int, int> > q;//队列用来进行bfs，记录入度的边的颜色。
        q.push(make_pair(0, RED));
        q.push(make_pair(0, BLUE));
        cost[0].first = cost[0].second = 0;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            for(auto oNode : G[node.first]){
                if(oNode.second == node.second){continue;}
                if(oNode.second == BLUE && cost[oNode.first].second != -1){continue;}
                if(oNode.second == RED && cost[oNode.first].first != -1){continue;}
                if(oNode.second == BLUE){cost[oNode.first].second = cost[node.first].first + 1;}
                else{cost[oNode.first].first = cost[node.first].second + 1;}
                q.push(make_pair(oNode.first, oNode.second));
            }
        }
        vector<int> res;
        for(int i = 0;i < n;i++){
            res.push_back((cost[i].first != -1 && cost[i].second != -1) ? min(cost[i].first, cost[i].second) : max(cost[i].first, cost[i].second));
        }
        return res;
    }
};