#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        if(nums1.size() == 0 || nums2.size() == 0){return res;}
        unordered_map<int, int> hash1, hash2;
        for(int item : nums1){hash1[item] += 1;}
        for(int item : nums2){hash2[item] += 1;}
        unordered_map<int, int>::iterator it;
        for(it = hash1.begin();it != hash1.end();it++){
            int times = min(it->second, hash2[it->first]);
            for(int i = 0;i < times;i++){res.push_back(it->first);}
        }
        return res;
    }
};