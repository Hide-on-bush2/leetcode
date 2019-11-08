#include<string>
#include<vector>
#include<utility>
#include<unordered_map>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        if(s == ""){
            return "";
        }
        unordered_map<char, int> myHash;
        for(char c : s){
            myHash[c] += 1;
        }
        vector< pair<char, int> > tempVec;
        unordered_map<char, int>::iterator it;
        for(it = myHash.begin();it != myHash.end();it++){
            pair<char, int> tempPair = make_pair(it->first, it->second);
            tempVec.push_back(tempPair);
        }
        for(int i = 0;i < tempVec.size() - 1;i++){
            for(int j = 0;j < tempVec.size() - i - 1;j++){
                if(tempVec[j].second < tempVec[j + 1].second ){
                    pair<char, int> tempPair = tempVec[j];
                    tempVec[j] = tempVec[j + 1];
                    tempVec[j + 1] = tempPair;
                }
            }
        }
        string res;
        for(int i = 0;i < tempVec.size();i++){
            for(int times = 0;times < tempVec[i].second;times++){
                res += tempVec[i].first;
            }
        }
        return res;
    }
};