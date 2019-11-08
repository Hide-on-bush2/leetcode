#include<queue>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector< vector<int> >& prerequisites) {
        vector<int> inDegree(numCourses, 0), outDegree(numCourses, 0);
        for(vector<int> path : prerequisites){
            outDegree[path[0]] += 1;
            inDegree[path[1]] += 1;
        }
        queue<int> node;
        for(int i = 0;i < numCourses;i++){
            if(inDegree[i] == 0){node.push(i);}
        }
        int count = 0;
        while(!node.empty()){
            int tempNode = node.front();
            node.pop();
            count++;
            for(vector<int> path : prerequisites){
                if(path[0] == tempNode){
                    if(--inDegree[path[1]] == 0){node.push(path[1]);}
                }
            }
        }
        if(count != numCourses){return false;}
        return true;
    }
};