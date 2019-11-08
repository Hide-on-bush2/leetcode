#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<unordered_map>
#include<algorithm>
#include<cstring>
using namespace std;
bool cmp(pair<string, int>& a, pair<string, int>& b){
    if(a.second == b.second){
        return a.first < b.first;
    } 
    return a.second < b.second;
}
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> myHash;
        for(string item : words){
            myHash[item] += 1;
        }
        vector< pair<string , int> > tempHeap;
        unordered_map<string, int>::iterator it;
        for(it = myHash.begin();it != myHash.end();it++){
            tempHeap.push_back(*it);
        }
        vector<string> res;
        make_heap(tempHeap.begin(), tempHeap.end(), cmp);
        while(k--){
            pop_heap(tempHeap.begin(), tempHeap.end(), cmp);
            string temp = tempHeap.back().first;
            res.push_back(temp);
            tempHeap.pop_back();
        }
        return res;
    }
};