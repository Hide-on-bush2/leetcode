
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int getNum(string& str){
        int i = 0;
        int result = 0;
        while(str[i] != ' ' && i < str.size()){
            result = result * 10 + str[i++] - '0';
        }
        return result;
    }
    string getDomain(string& str){
        int i = 0;
        while(str[i] != ' ' && i < str.size()){
            i++;
        }
        string result = "";
        while(i < str.size() - 1){
            result += str[++i];
        }
        return result;
    }
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> myHash;
        for(int i = 0;i < cpdomains.size();i++){
            int tempNum = getNum(cpdomains[i]);
            string tempStr = getDomain(cpdomains[i]);
            if(myHash.find(tempStr) != myHash.end()){
                myHash[tempStr] += tempNum;
            }
            else{
                myHash[tempStr] = tempNum;
            }
            for(int j = 0;j < tempStr.size();j++){
                if(tempStr[j] == '.'){
                    string chilStr = tempStr.substr(j + 1, tempStr.size());
                    if(myHash.find(chilStr) != myHash.end()){
                        myHash[chilStr] += tempNum;
                    }
                    else{
                        myHash[chilStr] = tempNum;
                    }
                }
            }
        }
        vector<string> myResult;
        unordered_map<string, int>::iterator it;
        for(it = myHash.begin();it != myHash.end();it++){
            auto domainsName = it->first;
            auto times = to_string(it->second);
            string tempStr = times + " " +domainsName;
            myResult.push_back(tempStr);
        }
        return myResult;
    }
};