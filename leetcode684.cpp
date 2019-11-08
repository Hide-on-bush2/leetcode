#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    void initializeDsu(vector<int>& A){
        for(int i = 0;i < A.size();i++){A[i] = -1;}
    }
    int find(vector<int>& A, int root){
        if(A[root] <= 0){return root;}
        else{return find(A, A[root]);}
    }
    bool unionDsu(vector<int>& A, int x, int y){
        int xf = find(A, x), yf = find(A, y);
        if(xf == yf){return false;}
        else if(A[xf] < A[yf]){A[yf] = xf;}
        else if(A[xf] == A[yf]){
            A[xf]--;
            A[yf] = xf;
        }
        else{A[xf] = yf;}
        return true;
    }
    vector<int> findRedundantConnection(vector< vector<int> >& edges) {
        vector<int> father(1000);
        initializeDsu(father);
        for(vector<int> edge : edges){
            if(!unionDsu(father, edge[0], edge[1])){return edge;}
        }
        return father;//没有用的
    }
};