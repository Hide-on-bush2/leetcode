#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using std::string;
using std::vector;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 
class Solution {
public:
    string numToStr(int x){
        string tempStr = "";
        if(x == 0){
            tempStr += char('0' + x);
            return tempStr;
        }
        if(x < 0){
            tempStr += "-";
            x = abs(x);
        }
        vector<int> myVec;
        while(x != 0){
            myVec.push_back(x % 10);
            x /= 10;
        }
        for(int i = myVec.size() - 1;i >= 0;i--){
            tempStr += char(myVec[i] + '0');
        }
        return tempStr;
    }
    string tree2str(TreeNode* t) {
        string tempStr = "";
        if(t == nullptr){
            return tempStr;
        }
        if(t->left == nullptr && t->right == nullptr){
            tempStr += numToStr(t->val);
            return tempStr;
        }
        tempStr += numToStr(t->val);
        tempStr += "(";
        if(t->left != nullptr){
            tempStr += tree2str(t->left);
        }
        tempStr += ")";
        if(t->right != nullptr){
            tempStr += "(";
            tempStr += tree2str(t->right);
            tempStr += ")";
        }
        return tempStr;
    }
};