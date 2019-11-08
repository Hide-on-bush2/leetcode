#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    struct cmp{
        bool operator()(int a, int b){
            return a > b;
        }
    }myCmp;
    int hIndex(vector<int>& citations) {
        int res = 0;
        if(citations.size() == 0){return 0;}
        sort(citations.begin(), citations.end(), myCmp);
        while(res < citations.size()){
            if(citations[res] < res + 1){break;}
            res++;
        }
        return res;
    }
};