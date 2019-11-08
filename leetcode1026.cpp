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
    int findMin(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        if(root->left == nullptr){
            return root->val;
        }
        return findMin(root->left);
    }
    int findMax(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        if(root->right == nullptr){
            return root->val;
        }
        return findMax(root->right);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        if(root->left == nullptr && root->right == nullptr){
            return 0;
        }
        int leftAbs = root->val - findMin(root->left);
        int rightAbs = findMax(root->right) - root->val;
        if(root->left == nullptr){
            return rightAbs;
        }
        if(root->right == nullptr){
            return leftAbs;
        }
        return leftAbs > rightAbs ? leftAbs : rightAbs;
    }
};