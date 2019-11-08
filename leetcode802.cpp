#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    
    vector<int> eventualSafeNodes(vector< vector<int> >& graph) {
        int size = graph.size();
        vector<bool> allvisit(size, false);
        vector<bool> safe(size, true);
        int count = size;
        while(count > 0){
            int tempNode;
            for(int i = 0;i < size;i++){
                if(allvisit[i] == false){
                    tempNode = i;
                    break;
                }
            }
            vector<int> paths;
            paths.push_back(tempNode);
            vector<bool> partvisit(size, false);
            while(paths.size() != 0){
                int node = paths.back();
                if(partvisit[node] == true){
                    paths.pop_back();
                    partvisit[node] = false;
                    continue;
                }
                if(allvisit[node] == false){count--;}
                partvisit[node] = allvisit[node] = true;
                if(graph[node].size() == 0){}
                else{
                    for(int next : graph[node]){
                        if(partvisit[next] == true){
                            for(int path : paths){
                                if(partvisit[path] == true){safe[path] = false;}
                            }
                            continue;
                        }
                        paths.push_back(next);
                    }
                }
            }         
        }
        vector<int> res;
        for(int i = 0;i < size;i++){
            if(safe[i] == true){res.push_back(i);}
        }
        return res;
    }
};