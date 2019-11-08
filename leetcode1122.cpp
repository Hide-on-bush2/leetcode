#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> hash;
        vector<int> res;
        if(!arr1.size()){return res;}
        for(int item : arr1){hash[item] += 1;}
        for(int item : arr2){
            for(int i = 0;i < hash[item];i++){
                res.push_back(item);
            }
            hash.erase(item);
        }
        unordered_map<int, int>::iterator it;
        vector<int> left;
        for(it = hash.begin();it != hash.end();it++){
            left.push_back(it->first);
        }
        sort(left.begin(), left.end());
        for(int item : left){
            for(int i = 0;i < hash[item];i++){
                res.push_back(item);
            }
        }
        return res;
    }
};