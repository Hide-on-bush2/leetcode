#include<vector>
#include<string>
#include<sstream>
#include<unordered_map>
#include<utility>
using namespace std;


class Solution {
public:
     pair<string, string> split(string& str){
        int i = 0;
        string file;
        string coment;
        while(i < str.size() && str[i++] != '('){}
        file = str.substr(0, i - 1);
        coment = str.substr(i, str.size() - 1);
        return make_pair(file, coment);
    }

    vector< vector<string> > findDuplicate(vector<string>& paths) {
        vector< vector<string> > res;
        if(paths.size() == 0){
            return res;
        }
        unordered_map<string, vector<string> > myHash;
        for(string s : paths){
            istringstream is(s);
            string out;
            vector<string> tempStr;
            while(is >> out){
                tempStr.push_back(out);
            }
            string paths = tempStr[0];
            for(int i = 1;i < tempStr.size();i++){
                pair<string, string> tempPair =  split(tempStr[i]);
                myHash[tempPair.second].push_back(paths + "/" + tempPair.first);
            }
        }
        unordered_map<string, vector<string> >::iterator it;
        for(it = myHash.begin();it != myHash.end();it++){
            if(it->second.size() > 1){
                res.push_back(it->second);
            }
        }
        return res;
    }
};