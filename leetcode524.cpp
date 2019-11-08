#include<algorithm>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    struct cmp{
        bool operator()(string& a, string& b){
            if(a.size() != b.size()){return a.size() > b.size();}
            else{return a < b;}
        }
    }myCmp;
    bool isSubstr(string& d, string& s){
        int i, j;
        for(i = 0, j = 0;i < d.size();i++, j++){
            char tempStr = d[i];
            if(j >= s.size()){return false;}
            while(s[j] != d[i]){
                if(j >= s.size()){return false;}
                j++;
            }
        }
        return true;
    }
    string findLongestWord(string s, vector<string>& d) {
        vector<string> res;
        for(string item : d){
            if(isSubstr(item, s)){res.push_back(item);}
        }
        if(!res.size()){return "";}
        sort(res.begin(), res.end(), myCmp);
        return res[0];
    }
};