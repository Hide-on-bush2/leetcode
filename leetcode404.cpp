#include<iostream>
#include<stack>
using std::stack;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 
class Solution {
private:
    stack<TreeNode*> treeStack;
public:
    bool isLeaves(TreeNode* root){
        return root != nullptr && root->left == nullptr && root->right == nullptr;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int result = 0;
        treeStack.push(root);
        while(!treeStack.empty()){
            TreeNode* tempTree = treeStack.top();
            treeStack.pop();
            if(isLeaves(tempTree->left)){
                result += tempTree->left->val;
            }
            if(tempTree->left != nullptr){
                treeStack.push(tempTree->left);
            }
            if(tempTree->right != nullptr){
                treeStack.push(tempTree->right);
            }
        }
        return result;
    }
};