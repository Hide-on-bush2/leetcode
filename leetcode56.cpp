#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    struct cmp{
        bool operator()(vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        }
    }myCmp;
    vector< vector<int> > merge(vector< vector<int> >& intervals) {
        vector< vector<int> > res;
        sort(intervals.begin(), intervals.end(), myCmp);
        if(intervals.size() == 0){return res;}
        for(vector<int> item : intervals){
            if(res.empty()){res.push_back(item);}
            else{
                vector<int> tempUnit = res.back();
                while(!res.empty() && tempUnit[1] >= item[0]){
                    res.pop_back();
                    vector<int> temp = {min(tempUnit[0], item[0]), max(tempUnit[1], item[1])};
                    item = temp;
                    if(res.empty()){break;}
                    tempUnit = res.back();
                }
                res.push_back(item);
            }
        }
        return res;
    }
};