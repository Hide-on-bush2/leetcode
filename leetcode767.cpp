#include<algorithm>
#include<iostream>
#include<unordered_map>
#include<queue>
#include<string>
#include<functional>
#include<utility>
using namespace std;

struct cmp{
    bool operator()(pair<char, int>& p1, pair<char, int>& p2){
        return p1.second > p2.second;
    }
};

class Solution {
public:
    
    string merge(string& str1, string& str2){
        string res = "";
        int i = 0;
        while(i < str1.size() && i < str2.size()){
            res += str2[i];
            res += str1[i];
            i++;
        }
        while(i < str1.size()){
            res += str1[i];
            i++;
        }
        while(i < str2.size()){
            res += str2[i];
            i++;
        }
        return res;
    }

    string reorganizeString(string S) {
        string res = "";
        if(S.size() == 0){
            return res;
        }
        unordered_map<char, int> myHash;
        for(char item : S){
            myHash[item] += 1;
        }
        priority_queue< pair<char, int>, vector< pair<char, int> >, cmp> myHeap;
        unordered_map<char, int>::iterator it;
        for(it = myHash.begin();it != myHash.end();it++){
            myHeap.push(*it);
        }
        int charNeed;
        while(!myHeap.empty()){
            pair<char, int> temp = myHeap.top();
            myHeap.pop();
            if(res.size() == 0){
                for(int i = 0;i < temp.second;i++){
                    res += temp.first;
                }
                charNeed = temp.second - 1;
                if(myHeap.empty()){
                    return "";
                }
                cout << res << endl;
            }
            else{
                charNeed = charNeed > temp.second ? charNeed - temp.second : 0;
                charNeed = temp.second > res.size() + 1 ? res.size() + 1 - temp.second : 0;
                string tempStr = "";
                for(int i = 0;i < temp.second;i++){
                    tempStr += temp.first;
                }
                reverse(res.begin(), res.end());
                if(res.size() > temp.second){
                    res = merge(tempStr, res);
                }
                else{
                    res = merge(res, tempStr);
                }
                cout << res << endl;
            }
        }
        if(charNeed != 0){
            return "";
        }
        return res;
    }
};

