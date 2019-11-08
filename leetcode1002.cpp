#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    void hashStr(string& str, unordered_map<char, int>& hash){
        for(char c : str){
            if(hash.find(c) == hash.end()){
                hash[c] = 1;
            }
            else{
                hash[c] += 1;
            }
        }
    }
    
    vector<string> commonChars(vector<string>& A) {
        int size = A.size();
        unordered_map<char, int> myHash[size];
        for(int i = 0;i < size;i++){
            hashStr(A[i], myHash[i]);
        }
        unordered_map<char, int>::iterator it;
        vector<string> myResult;
        for(it = myHash[0].begin();it != myHash[0].end();it++){
            char key = it->first;
            int num = it->second;
            bool flag = true;
            for(int i = 0;i < num;i++){
                string temp = "";
                for(int i = 1;i < size;i++){
                    if(myHash[i].find(key) == myHash[i].end() || myHash[i][key] == 0){
                        flag = false;
                        break;
                    }
                    myHash[i][key]--;
                }
                if(flag){
                    temp += key;
                    myResult.push_back(temp);
                }
            }
        }
        return myResult;
    }
};