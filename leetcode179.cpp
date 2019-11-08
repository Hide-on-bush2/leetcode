#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


class Solution {
public:
    vector<int> split(int num){
        vector<int> res;
        if(num == 0){
            res.push_back(num);
            return res;
        }
        while(num){
            res.push_back(num % 10);
            num /= 10;
        }
        return res;
    }
    struct cmp{
        vector<int> split(int num){
        vector<int> res;
        if(num == 0){
            res.push_back(num);
            return res;
        }
        while(num){
            res.push_back(num % 10);
            num /= 10;
        }
        return res;
    }
        bool operator()(int a, int b){
            if(a == b){return true;}
            vector<int> arrayA = split(a);
            vector<int> arrayB = split(b);
            int i = 0;
            while(i < arrayA.size() && i < arrayB.size()){
                if(arrayA[i] > arrayB[i]){return true;}
                else if(arrayA[i] < arrayB[i]){return false;}
                i++;
            }
            if(i == arrayA.size()){return arrayA[0] > arrayB[i];}
            else if(i == arrayB.size()){return arrayA[i] > arrayB[0];}
            return true;
        }
    }myCmp;
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), myCmp);
        string res = "";
        if(nums.size() == 0){return res;}
        for(int item : nums){
            vector<int> temp = split(item);
            reverse(temp.begin(), temp.end());
            for(int cell : temp){res += '0' + cell;}
        }
        return res;
    }
};