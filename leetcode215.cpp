#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(int a, int b){
        return a < b;
    }
class Solution {
public:
    
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end(), cmp);
        int res;
        while(k--){
            pop_heap(nums.begin(), nums.end(), cmp);
            res = nums.back();
            nums.pop_back();
        }
        return res;
    }
};