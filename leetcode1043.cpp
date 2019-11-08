#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        if(A.size() == 0){return 0;}
        int left = A.size();
        int res = 0;
        while(left > 0){
            make_heap(A.begin(), A.end());
            int max_item = A.front();
            if(K <= left){
                res += max_item * K;
                left -= K;
            }
            else{
                res += max_item * left;
                break;
            }
            pop_heap(A.begin(), A.end());
            A.pop_back();
        }
        return res;
    }
};