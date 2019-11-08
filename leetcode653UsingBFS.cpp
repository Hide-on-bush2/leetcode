#include<iostream>
#include<queue>
#include<vector>
using std::queue;
using std::vector;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
private:
    queue<TreeNode*> myQueue;
    vector<int> myVec;
public:
    bool contain(vector<int>& vec, int target){
        for(int i = 0;i < vec.size();i++){
            if(target == vec[i]){
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
        if(root->right != nullptr){
            myQueue.push(root->right);
        }
        if(root->left != nullptr){
            myQueue.push(root->left);
        }
        while(!myQueue.empty()){
            TreeNode* tempPtr = myQueue.front();
            myQueue.pop();
            if(contain(myVec, k - tempPtr->val)){
                return true;
            }
            myVec.push_back(tempPtr->val);
            if(tempPtr->left != nullptr){
                myQueue.push(tempPtr->left);
            }
            if(tempPtr->right != nullptr){
                myQueue.push(tempPtr->right);
            }
        }
        return false;
    }
};