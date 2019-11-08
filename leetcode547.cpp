#include<unordered_set>
#include<vector>
using namespace std;
class Solution {
public:
    void initializeDsu(vector<int>& A){
        for(int i = 0;i < A.size();i++){A[i] = i;}
    }
    int find(vector<int>& A, int element){
        if(A[element] == element){return element;}
        else{return find(A, A[element]);}
    }
    void dsuUnion(vector<int>& A, int root1, int root2){
        A[find(A, root1)] = find(A, root2);
    }
    int findCircleNum(vector< vector<int> >& M) {
        if(M.size() == 0){return 0;}
        vector<int> dsu(M.size());
        initializeDsu(dsu);
        int numOfFriends = M.size();
        for(int i = 0;i < numOfFriends;i++){
            for(int j = 0;j < numOfFriends;j++){
                if(M[i][j] == 1){
                    dsuUnion(dsu ,i, j);
                }
            }
        }
        unordered_set<int> friends;
        for(int i = 0;i < M.size();i++){
            friends.insert(find(dsu, i));
        }
        return friends.size();
    }
};