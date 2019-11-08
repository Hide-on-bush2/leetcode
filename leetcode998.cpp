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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* tempNode = new TreeNode(val);
        if(root == nullptr){
            return tempNode;
        }
        if(val > root->val){
            tempNode->left = root;
            return tempNode;
        }
        root->right = insertIntoMaxTree(root->right, val);
        return root;
    }
};