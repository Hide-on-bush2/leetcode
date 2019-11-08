#include<string>
#include<iostream>
#include<stack>
#include<utility>
#include<vector>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 
class Solution {
private:
    stack< pair<TreeNode*, int> > myStack;
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
        tempStr += numToStr(t->val);
        if(t->right != nullptr){
            myStack.push(pair<TreeNode*, int>(t->right, 0));
        }
        if(t->right != nullptr || t->left != nullptr){
            myStack.push(pair<TreeNode*, int>(t->left, 0));
        }
        while(!myStack.empty()){
            pair<TreeNode*, int> ptr = myStack.top();
            if(ptr.second == 0){
                pair<TreeNode*, int> tempPtr = make_pair(ptr.first, 1);
                myStack.pop();
                myStack.push(tempPtr);
                tempStr += "(";
                if(ptr.first != nullptr){
                    tempStr += numToStr(ptr.first->val);
                    if(ptr.first->right != nullptr){
                        myStack.push(pair<TreeNode*, int>(ptr.first->right, 0));
                    }
                    if(ptr.first->left != nullptr || ptr.first->right != nullptr){
                        myStack.push(pair<TreeNode*, int>(ptr.first->left, 0));
                    }
                }
            }
            else{
                tempStr += ")";
                myStack.pop();
            }
        }
        return tempStr;
    }
};