#include<iostream>
#include<stack>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 
class Solution {
private:
    stack<TreeNode*> myStack;
public:
    void pushLeft(TreeNode* root){
        if(root == nullptr){
            return;
        }
        pushLeft(root->left);
        myStack.push(root);
        pushLeft(root->right);
    }
    TreeNode* convertBST(TreeNode* root) {
        if(root == nullptr){
            return root;
        }
        pushLeft(root);
        int sum = 0;
        while(!myStack.empty()){
            TreeNode* tempNode = myStack.top();
            tempNode->val += sum;
            sum = tempNode->val;
            myStack.pop();
        }
        return root;
    }
};