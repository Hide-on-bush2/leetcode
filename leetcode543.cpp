#include<cmath>
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
    int lenOfTree(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        return 1 + max(lenOfTree(root->left), lenOfTree(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        myStack.push(root);
        int tempLen = 0;
        while(!myStack.empty()){
            TreeNode* tempNode = myStack.top();
            myStack.pop();
            tempLen = tempLen > lenOfTree(tempNode->right) + lenOfTree(tempNode->left) ? tempLen : lenOfTree(tempNode->right) + lenOfTree(tempNode->left);
            if(tempNode->left != nullptr){
                myStack.push(tempNode->left);
            }
            if(tempNode->right != nullptr){
                myStack.push(tempNode->right);
            }
        }
        return tempLen;
    }
};