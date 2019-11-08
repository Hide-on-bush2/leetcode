#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> map(1001);
        map[0] = map[1] = 0;
        int size = cost.size();
        for(int i = 2;i < size;i++){map[i] = min(map[i - 1] + cost[i - 1], map[i - 2] + cost[i - 2]);}
        return min(map[size - 1] + cost[size - 1], map[size - 2] + cost[size - 2]);
    }
};