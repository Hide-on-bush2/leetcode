#include<cmath>
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
    int getDepth(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        return 1 + max(getDepth(root->left), getDepth(root->right));
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root == nullptr){
            return root;
        }
        int depthOfLeft = getDepth(root->left);
        int depthOfRight = getDepth(root->right);
        if(depthOfLeft == depthOfRight){
            return root;
        }
        return depthOfLeft > depthOfRight ? subtreeWithAllDeepest(root->left) : subtreeWithAllDeepest(root->right);
    }
};