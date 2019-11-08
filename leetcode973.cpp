#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b){
        return (pow(a[0], 2) + pow(a[1], 2)) > (pow(b[0], 2) + pow(b[1], 2));
    }

class Solution {
public:
    void PrintContainer(vector< vector<int> >& vec){
        for(vector<int> bitem : vec){
            cout << "(";
            for(int sitem :  bitem){
                cout << sitem << " ";
            }
            cout << ") ";
        }
        cout << endl;
    }
    vector< vector<int> > kClosest(vector< vector<int> >& points, int K) {
        vector< vector<int> > res;
        if(points.size() == 0){
            return res;
        }
        make_heap(points.begin(), points.end(), cmp);
        PrintContainer(points);
        for(int i = 0;i < K;i++){
            pop_heap(points.begin(), points.end(), cmp);
            PrintContainer(points);
            vector<int> temp = points.back();
            points.pop_back();
            PrintContainer(points);
            res.push_back(temp);
        }
        return res;
    }
};