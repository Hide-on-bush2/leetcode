#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector< vector<int> > flipAndInvertImage(vector< vector<int> >& A) {
        for(vector<int> a : A){
            reverse(a.begin(), a.end());
        }
        for(vector<int> a : A){
            cout << "[";
            for(int _a : a){
                cout << _a << " ";
            }
            cout << "]";
        }
        for(vector<int> a : A){
            for(int _a : a){
                _a = _a == 0;
            }
        }
        return A;
    }
};