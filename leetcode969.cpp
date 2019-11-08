#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    // int findIndex(int val, vector<int>& target){
    //     int i;
    //     for(i = 0;i < target.size();i++){
    //         if(target[i] == val){return i;}
    //     }
    //     return -1;
    // }

    void printVector(vector<int>& vec){
        for(int item : vec){cout << item << " ";}
        cout << endl;
    }
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> res;
        if(!A.size()){return res;}
        int k = 0;
        while(k < A.size()){
            cout << "K:" << k << endl;
            vector<int>::iterator maxItem = max_element(A.begin(), A.end() - k);
            int idx = int(maxItem - A.begin());
            res.push_back(idx + 1);
            cout << "push" << idx + 1 << endl;          
            reverse(A.begin(), A.begin() + idx + 1);
            printVector(A);
            reverse(A.begin(), A.end() - k);
            res.push_back(A.size() - k);
            cout << "push" << A.size() - k << endl;
            printVector(A);
            k++;
        }
        return res;
    }
};