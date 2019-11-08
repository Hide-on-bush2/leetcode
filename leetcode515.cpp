#include<queue>
#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> myResult;
        if(root == nullptr){
            return myResult;
        }
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        while(!myQueue.empty()){
            int times = myQueue.size();
            int maxVal = myQueue.front()->val;
            for(int i = 0;i < times;i++){
                TreeNode* tempNode = myQueue.front();
                myQueue.pop();
                maxVal = maxVal > tempNode->val ? maxVal : tempNode->val;
                if(tempNode->left != nullptr){
                    myQueue.push(tempNode->left);
                }
                if(tempNode->right != nullptr){
                    myQueue.push(tempNode->right);
                }
            }
            myResult.push_back(maxVal);
        }
        return myResult;
    }
};