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
    TreeNode* convertBST(TreeNode* root) {
        if(root == nullptr){
            return root;
        }
        TreeNode* tempNode = root;
        int sum = 0;
        while(tempNode != nullptr || !myStack.empty()){
            while(tempNode != nullptr){
                myStack.push(tempNode);
                tempNode = tempNode->right;
            }
            tempNode = myStack.top();
            myStack.pop();
            tempNode->val += sum;
            sum = tempNode->val;
            tempNode = tempNode->left;
        }
        return root;
    }
};