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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr){
            TreeNode* tempNode = new TreeNode(val);
            return tempNode;
        }
        if(val < root->val){
            root->left = insertIntoBST(root->left, val);
        }
        else{
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};