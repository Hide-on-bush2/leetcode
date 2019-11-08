#include<unordered_map>
#include<iostream>
#include<vector>
#include<utility>
using namespace std;


class Solution {
public:
    const int Alice = 0;
    const int Bob = 1; 
    vector<int> factor(int N){
        vector<int> res;
        for(int i = 1;i < N;i++){
            if(N % i == 0){res.push_back(i);}
        }
        return res;
    }
    int Max(vector<int>& v){
        auto it = max_element(v.begin(), v.end());
        return *it;
    }
    int Min(vector<int>& v){
        auto it = min_element(v.begin(), v.end());
        return *it;
    }
    int Map[10000][2];
    int dp(int N, int player, int Map[][2]){
        if(Map[N][player] != 0){return Map[N][player];}
        if(N == 1 && player == Alice){return -1;}
        if(N == 1 && player == Bob){return 1;}
        vector<int> factors = factor(N);
        vector<int> dpRes;
        for(int x : factors){
            if(player == Alice){dpRes.push_back(dp(N - x, Bob, Map));}
            else{dpRes.push_back(dp(N - x, Alice, Map));}
        }
        int res;
        if(player == Alice){res = Max(dpRes);}
        else{res = Min(dpRes);}
        return Map[N][player] = res;
    }
    bool divisorGame(int N) {
        return dp(N, Alice, Map) == 1;
    }
};