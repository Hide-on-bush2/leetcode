#include<map>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    map<int, int> Map;
    int dp(int index, vector<int>& nums){
        if(Map.find(index) != Map.end()){return Map[index];}
        if(index == 0 || index == 1){return Map[index] = nums[index];}
        int max = nums[0];
        for(int i = 0;i <= index - 2;i++){
            int temp = dp(i, nums);
            max = max > temp ? max : temp;
        }
        return Map[index] = max + nums[index];
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 0){return 0;}
        dp(nums.size() - 1, nums);
        if(nums.size() > 1){dp(nums.size() - 2, nums);}
        int max = nums[0];
        map<int, int>::iterator it;
        for(it = Map.begin();it != Map.end();it++){max = max > it->second ? max : it->second;}
        return max;
    }
};