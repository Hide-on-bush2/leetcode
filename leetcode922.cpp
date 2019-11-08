#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> odd;
        vector<int> even;
        for(int i = 0;i < A.size();i++){
            if(A[i] % 2){odd.push_back(A[i]);}
            else{even.push_back(A[i]);}
        }
        vector<int> res(A.size());
        for(int i = 0, j = 0;i < A.size();i += 2, j++){res[i] = even[j];}
        for(int i = 1, j =0;i < A.size();i += 2, j++){res[i] = odd[j];}
        return res;
    }
};