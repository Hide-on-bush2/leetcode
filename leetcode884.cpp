#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> myResult;
        unordered_map<string, int> myHash;
        int i = 0;
        while(i < A.size()){
            string tempStr = "";
            while(i < A.size() && A[i] != ' '){
                tempStr += A[i++];
            }
            if(myHash.find(tempStr) != myHash.end()){
                myHash[tempStr] += 1;
            }
            else{
                myHash[tempStr] = 1;
            }
            i++;
        }
        i = 0;
        while(i < B.size()){
            string tempStr = "";
            while(i < B.size() && B[i] != ' '){
                tempStr += B[i++];
            }
            if(myHash.find(tempStr) != myHash.end()){
                myHash[tempStr] += 1;
            }
            else{
                myHash[tempStr] = 1;
            }
            i++;
        }
        unordered_map<string, int>::iterator it;
        for(it = myHash.begin();it != myHash.end();it++){
            if(it->second == 1){
                myResult.push_back(it->first);
            }
        }
        return myResult;
    }
};