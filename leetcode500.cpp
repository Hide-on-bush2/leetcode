#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    void setHash(unordered_map<char, int>& hashTable, string str, int row){
        for(char c : str){
            hashTable[c] = row;
            char upper = c - 32;
            hashTable[upper] = row;
        }
    }
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, int> myHash;
        setHash(myHash, "qwertyuiop", 1);
        setHash(myHash, "asdfghjkl", 2);
        setHash(myHash, "zxcvbnm", 3);
        cout << myHash['q'] << endl;
        vector<string> myResult;
        for(string s : words){
            bool condition = true;
            int row = myHash[s[0]];
            for(int i = 1;i < s.size();i++){
                if(myHash[s[i]] != row){
                    condition = false;
                    break;
                }
            }
            if(condition){
                myResult.push_back(s);
            }
        }
        return myResult;
    }
};