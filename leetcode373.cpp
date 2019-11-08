#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// class Solution {
// public:
//     vector< vector<int> > kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
//         vector< vector<int> > res;
//         if(nums1.size() == 0 || nums2.size() == 0){return res;}
//         vector<int>::iterator it1 = nums1.begin(), it2 = nums2.begin();
//         while(res.size() != k){
//             if((it1 + 1) == nums1.end() && (it2 + 1) == nums2.end()){break;}
//             vector<int> temp(2);
//             temp[0] = *it1;
//             temp[1] = *it2;
//             res.push_back(temp);
//             if(it1 + 1 == nums1.end()){it2 += 1;}
//             else if(it2 + 1 == nums2.end()){it1 += 1;}
//             else if(*it1 + *(it2 + 1) < *it2 + *(it1 + 1)){it2 += 1;}
//             else{it1 += 1;}
//         }
//         return res;
//     }
// };
//错误的算法
class Solution {
public:
    struct cmp{
        bool operator()(vector<int>& a, vector<int>& b){
            return a[0] + a[1] < b[0] + b[1];
        }
    }myCmp;
    vector< vector<int> > kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector< vector<int> > res;
        if(nums1.size() == 0 || nums2.size() == 0){return res;}
        for(int a : nums1){
            for(int b : nums2){
                vector<int> temp = {a, b};
                res.push_back(temp);
            }
        }
        sort(res.begin(), res.end(), myCmp);
        if(res.size() < k){return res;}
        vector< vector<int> > realRes(res.begin(), res.begin() + k);
        return realRes;
    }
};