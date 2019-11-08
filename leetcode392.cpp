#include<utility>
#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    map<pair<int, int>, int> Map;
    int dp(int s_idx, int t_idx, string& s, string& t){
        if(Map.find(make_pair(s_idx, t_idx)) != Map.end()){return Map[make_pair(s_idx, t_idx)] == 1;}
        if(s_idx == s.size()){return 1;}
        char node = s[s_idx];
        int i;
        for(i = t_idx;i < t.size();i++){
            if(t[i] == node){break;}
        }
        if(i == t.size()){return -1;}
        return Map[make_pair(s_idx, t_idx)] = dp(s_idx + 1, i + 1, s, t);
    }
    bool isSubsequence(string s, string t) {
        return dp(0, 0, s, t) == 1;
    }
};