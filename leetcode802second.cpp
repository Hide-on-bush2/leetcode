#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector< vector<int> >& graph) {
        int size = graph.size();
        vector<bool> safe(size, false);
        vector<bool> known(size, false);
        queue<int> noOutDegree;
        for(int i = 0;i < size;i++){
            if(graph[i].size() == 0){
                noOutDegree.push(i);
                known[i] = true;
            }
        } 
        while(!noOutDegree.empty()){
            int tempNode = noOutDegree.front();
            safe[tempNode] = true;
            noOutDegree.pop();
            for(int i = 0;i < size;i++){
                for(vector<int>::iterator it = graph[i].begin();it != graph[i].end();){
                    if(*it == tempNode){it = graph[i].erase(it);}
                    else{it++;}
                }
            }
            for(int i = 0;i < size;i++){
                if(graph[i].size() == 0 && !known[i]){
                    noOutDegree.push(i);
                    known[i] = true;
                }
            }
        }
        vector<int> res;
        for(int i = 0;i < size;i++){
            if(safe[i]){res.push_back(i);}
        }
        return res;
    }
};