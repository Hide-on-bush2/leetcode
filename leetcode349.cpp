#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        if(nums1.size() == 0 || nums2.size() == 0){return res;}
        unordered_map<int, int> hash1, hash2;
        for(int item : nums1){hash1[item] += 1;}
        for(int item : nums2){hash2[item] += 1;}
        unordered_map<int, int>::iterator it1;
        for(it1 = hash1.begin();it1 != hash1.end();it1++){
            if(hash2[it1->first] > 0){
                res.push_back(it1->first);
            }
        }
        return res;
    }
};