#include<queue>
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        TreeNode* tempLeft;
        while(!myQueue.empty()){
            tempLeft = myQueue.front();
            int times = myQueue.size();
            for(int i = 0;i < times;i++){
                TreeNode* tempNode = myQueue.front();
                myQueue.pop();
                if(tempNode->left != nullptr){
                    myQueue.push(tempNode->left);
                }
                if(tempNode->right != nullptr){
                    myQueue.push(tempNode->right);
                }
            }
        }
        return tempLeft->val;
    }
};