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
    int sumOfPath(TreeNode* root, int result){
        if(root == nullptr){
            return 0;
        }
        if(root->left == nullptr && root->right == nullptr){
            return result * 2 + root->val;
        }
        return sumOfPath(root->left, result * 2 + root->val) + sumOfPath(root->right, result * 2 + root->val);
    }
    int sumRootToLeaf(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        if(root->left == nullptr && root->right == nullptr){
            return root->val;
        }
        if(root->left == nullptr){
            return sumOfPath(root->right, root->val);
        }
        if(root->right == nullptr){
            return sumOfPath(root->left, root->val);
        }
        return sumOfPath(root, 0);   
    }
};