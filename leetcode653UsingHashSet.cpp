#include<iostream>
#include<vector>
#include<stack>
using std::stack;
using std::vector;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
private:
    vector<int> myVec;
    stack<TreeNode*> mySta; 
public:
    bool sumExit(vector<int>& vc, int target){
        for(int i = 0;i < vc.size();i++){
            if(vc[i] == target){
                return true;
            }
        }
        return false;
    } 
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr || (root->left == nullptr && root->right == nullptr)){
            return false;
        }
        myVec.push_back(root->val);
        if(root->left != nullptr){
            mySta.push(root->left);
        }
        if(root->right != nullptr){
            mySta.push(root->right);
        }
        while(!mySta.empty()){
            TreeNode* tempPtr = mySta.top();
            mySta.pop();
            if(sumExit(myVec, k - tempPtr->val)){
                return true;
            }
            myVec.push_back(tempPtr->val);
            if(tempPtr->left != nullptr){
                mySta.push(tempPtr->left);
            }
            if(tempPtr->right != nullptr){
                mySta.push(tempPtr->right);
            }
        }
        return false;
    }
};