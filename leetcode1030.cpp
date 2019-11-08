#include<cmath>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    struct cmp{
        int r0;
        int c0;
        bool operator()(vector<int>& a, vector<int>& b){
            return abs(a[0] - r0) + abs(a[1] - c0) < abs(b[0] - r0) + abs(b[1] - c0);
        }
        cmp(int r, int c):r0(r), c0(c){}
    };
    vector< vector<int> > allCellsDistOrder(int R, int C, int r0, int c0) {
        vector< vector<int> > res;
        for(int i = 0;i < R;i++){
            for(int j = 0;j < C;j++){
                vector<int> temp = {i, j};
                res.push_back(temp);
            }
        }
        cmp myCmp(r0, c0);
        sort(res.begin(), res.end(), myCmp);
        return res;
    }
};