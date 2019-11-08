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
    bool toBeDel(TreeNode* root){
        return root->val == 0 && root->left == nullptr && root->right == nullptr;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(root == nullptr){
            return root;
        }
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if(toBeDel(root)){
            return nullptr;
        }
        return root;
    }
};