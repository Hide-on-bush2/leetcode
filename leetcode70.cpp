#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    vector<int> map;
public:
    Solution():map(vector<int>(1001, -1)){}
    int climbStairs(int n) {
        if(map[n] != -1){return map[n];}
        if(n == 0 || n == 1){return 1;}
        return map[n] = climbStairs(n - 1) + climbStairs(n - 2);
    }
};