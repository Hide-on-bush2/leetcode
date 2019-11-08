#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
//所以这道题跟优先队列有什么关系吗？
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> counter;
        unordered_map<int, int> tail;
        for(int x : nums){counter[x] += 1;}
        for(int x : nums){
            if(counter[x] == 0){continue;}
            else if(tail[x] > 0){
                tail[x] -= 1;
                tail[x + 1] += 1;
            }
            else if(counter[x + 1] > 0 && counter[x + 2] > 0){
                counter[x + 1] -= 1;
                counter[x + 2] -= 1;
                tail[x + 3] += 1;
            }
            else{return false;}
            counter[x]--;
        }
        return true;
    }
};

