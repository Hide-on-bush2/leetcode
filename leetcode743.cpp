#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

struct cmp{
    bool operator()(vector<int>& v1, vector<int>& v2){
        return v1[0] > v2[0];
    }
};

class Solution {
public:
    int networkDelayTime(vector< vector<int> >& times, int N, int K) {
        priority_queue<vector<int>, vector< vector<int> >, cmp > myHeap;
        int res = 0;
        for(vector<int> item : times){
            myHeap.push(item);
        }
        int node = -1;
        while(!myHeap.empty()){
            vector<int> temp = myHeap.top();
            myHeap.pop();
            if(node == -1){
                res += 
            }
        }
    
    }
};