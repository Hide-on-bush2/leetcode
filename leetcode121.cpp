#include<iostream>
#include<vector>

using namespace std;


class Solution {
private:
    vector<int> map;    
public:
    Solution():map(100001, -1){}
    int dp(int index, vector<int>& prices){
        if(map[index] != -1){return map[index];}
        if(index == 0){return 0;}
        int max_item = -100000;
        for(int i = 0;i < index;i++){
            int temp = dp(i, prices) - prices[i];
            max_item = max(max_item, temp);
        }
        if(max_item + prices[index] < 0){return map[index] = 0;}
        return map[index] = max_item + prices[index];
    }
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0 || prices.size() == 1){return 0;}
        dp(prices.size() - 1, prices);
        auto it = max_element(map.begin(), map.begin() + prices.size());
        return *it;
    }
};