#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> myHash;
        for(int item : nums){
            myHash[item] += 1;
        }
        unordered_map<int, int>::iterator it;
        for(it = myHash.begin();it != myHash.end();it++){
            if(it->second == 1){
                return it->first;
            }
        }
        return 0;
    }
};