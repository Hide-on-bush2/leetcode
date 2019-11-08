#include<map>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    map<int, int> Map;
    int dp(int index, vector<int>& nums){
        if(Map.find(index) != Map.end()){return Map[index];}
        if(index == 0){return Map[index] = nums[index];}
        int pre = dp(index - 1, nums);
        return Map[index] = pre > 0 ? pre + nums[index] : nums[index];
    }
    int maxSubArray(vector<int>& nums) {
        dp(nums.size() - 1, nums);
        int max = nums[0];
        map<int, int>::iterator it;
        for(it = Map.begin();it != Map.end();it++){
            cout << it->first << ":" << it->second << endl;
            max = it->second > max ? it->second : max;
        }
        return max;
    }
};