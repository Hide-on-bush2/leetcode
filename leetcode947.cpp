#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    void InitializeDsu(vector<int>& A){
        for(int i = 0;i < A.size();i++){A[i] = i;}
    }
    int Find(vector<int>& A, int element){
        if(A[element] == element){return element;}
        else{return Find(A, A[element]);}
    }
    void Union(vector<int>& A, int root1, int root2){
        A[Find(A, root2)] = Find(A, root1);
    }

    int removeStones(vector< vector<int> >& stones) {
        vector<int> father(stones.size());
        InitializeDsu(father);
        unordered_map< int, vector<int> > rowMap, colMap;
        for(int i = 0;i < stones.size();i++){
            rowMap[stones[i][0]].push_back(i);
            colMap[stones[i][1]].push_back(i);
        }
        for(int i = 0;i < stones.size();i++){
            for(int j : rowMap[stones[i][0]]){Union(father, i, j);}
            for(int j : colMap[stones[i][1]]){Union(father, i, j);}
        }
        unordered_set<int> unique;
        for(int item : father){
            unique.insert(Find(father, item));
        }
        return father.size() - unique.size();
    }
};