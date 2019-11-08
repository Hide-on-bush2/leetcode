#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findJudge(int N, vector< vector<int> >& trust) {
        vector<int> inDegree(N, 0), outDegree(N, 0);
        for(vector<int> temp : trust){
            inDegree[temp[1] - 1] += 1;
            outDegree[temp[0] - 1] += 1;
        }
        for(int i = 0;i < N;i++){
            if(inDegree[i] == N - 1 && outDegree[i] == 0){
                return i + 1;
            }
        }
        return -1;
    }
};