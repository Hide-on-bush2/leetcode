#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int, int> hash;
        for(int item : nums){hash[item] += 1;}      
        vector<int> res;
        for(int i = 0;i < hash[0];i++){res.push_back(0);}
        for(int i = 0;i < hash[1];i++){res.push_back(1);}
        for(int i = 0;i < hash[2];i++){res.push_back(2);}
        nums = res;
    }
};