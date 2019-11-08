#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end(), greater<int>());
        int i = 0;
        while(i < A.size() - 2){
            if(A[i] < A[i + 1] + A[i + 2]){return A[i] + A[i + 1] + A[i + 2];}
            i++;
        }
        return 0;
    }
};