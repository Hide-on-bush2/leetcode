#include<iostream>
#include<vector>
using namespace std;
//自顶向下版本
class Solution {
public:
    int map[1001];
    int dp(int index, vector<int>& cost){
        if(map[index] != 0){return map[index];}
        if(index == 0 || index == 1){return cost[index];}
        int dp1 = dp(index - 1, cost), dp2 = dp(index - 2, cost);
        int res = dp1 > dp2 ? dp2 + cost[index] : dp1 + cost[index];
        return map[index] = res;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        return min(dp(cost.size() - 1, cost), dp(cost.size() - 2, cost));
    }
};