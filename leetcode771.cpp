#include<string>
#include<ext/hash_map>
using namespace std;
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        __gnu_cxx::hash_map<char, int> myHash;
        for(char c : J){
            myHash[c] = 1;
        }
        int num = 0;
        for(char c : S){
            if(myHash.find(c) != myHash.end()){
                num ++;
            }
        }
        return num;
    }
};