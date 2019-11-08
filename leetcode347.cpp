#include<vector>
#include<algorithm>
#include<unordered_map>
#include<iostream>
#include<utility>
using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b){
    return a.second < b.second;
}
class Solution {
public:
    void PrintContainer(vector< pair<int, int> >& vec){
        for(pair<int, int> item : vec){
            cout << "[" << item.first << "," << item.second << "]" << " ";
        }
        cout << endl;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> myHash;
        for(int item : nums){
            myHash[item] += 1;
        }
        vector< pair<int, int> > vec;
        unordered_map<int, int>::iterator it;
        for(it = myHash.begin();it != myHash.end();it++){
            vec.push_back(*it);
        } 
        vector<int> res;
        make_heap(vec.begin(), vec.end(), cmp);
        PrintContainer(vec);
        for(int i = 0;i < k;i++){
            pop_heap(vec.begin(), vec.end(), cmp);
            PrintContainer(vec);
            int temp = vec.back().first;
            vec.pop_back();
            PrintContainer(vec);
            res.push_back(temp);
        }
        return res;
    }
};