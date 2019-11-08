#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector< vector<int> > levelOrderBottom(TreeNode* root) {
        vector< vector<int> > myResult;
        queue<TreeNode*> queueOne;
        queue<TreeNode*> queueTwo;
        if(root == nullptr){
            return myResult;
        }        
        queueOne.push(root);
        while(!queueOne.empty()){
            vector<int> tempVec;
            while(!queueOne.empty()){
                TreeNode* tempNode = queueOne.front();
                tempVec.push_back(tempNode->val);
                queueOne.pop();
                if(tempNode->left != nullptr){
                    queueTwo.push(tempNode->left);
                }
                if(tempNode->right != nullptr){
                    queueTwo.push(tempNode->right);
                }
            }
            queueOne = queueTwo;
            while(!queueTwo.empty()){
                queueTwo.pop();
            }
            myResult.push_back(tempVec);
        }
        reverse(myResult.begin(), myResult.end());
        return myResult;
    }
};