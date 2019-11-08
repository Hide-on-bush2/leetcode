#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> gardenNoAdj(int N, vector< vector<int> >& paths) {
        vector<int> color(N, 0);
        vector< vector<int> > connectNode(N);
        for(vector<int> path : paths){
            connectNode[path[0] - 1].push_back(path[1] - 1);
            connectNode[path[1] - 1].push_back(path[0] - 1);
        }
        vector< vector<int> > colorAlowed(N, vector<int>(4));
        for(int i = 0;i < N;i++){
            for(int j = 0;j < 4;j++){
                if(colorAlowed[i][j] == 0){
                    color[i] = j + 1;
                    for(int except : connectNode[i]){
                        colorAlowed[except][j] = 1;
                    }
                    break;
                }
            }
        }
        return color;
    }
};