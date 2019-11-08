#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_map<int, int> myHash;
        for(int item : A){
            if(myHash.find(item) != myHash.end()){
                return item;
            }
            else{
                myHash[item] = 1;
            }
        }
        return 0;
    }
};