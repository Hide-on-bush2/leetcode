#include<iostream>
#include<vector>
#include<unordered_map>
#include<utility>
#include<queue>
using namespace std;


class Solution {
public:
    struct cmp{
        bool operator()(const pair<int, int>& a, const pair<int, int>& b){
            return a.second < b.second;
        }
    };
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        vector<int> res(barcodes.size());
        if(res.size() == 0){return res;}
        unordered_map<int, int> hash;
        for(int item : barcodes){hash[item] += 1;}
        priority_queue< pair<int, int>, vector< pair<int, int> >, cmp> pq;
        for(unordered_map<int, int>::iterator it = hash.begin();it != hash.end();it++){
            pq.push(*it);
        }
        vector<int> temp;
        while(!pq.empty()){
            pair<int, int> tempNode = pq.top();
            pq.pop();
            for(int i = 0;i < tempNode.second;i++){temp.push_back(tempNode.first);}
        }
        int j = 0;
        for(int i = 0;i < barcodes.size();i += 2){res[i] = temp[j++];}
        for(int i = 1;i < barcodes.size();i += 2){res[i] = temp[j++];}
        return res;
    }
};