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
    int coinsNeed(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        return 1 - root->val + coinsNeed(root->left) + coinsNeed(root->right); 
    }
    int rootToChi(TreeNode* root, int coins){
        if(root == nullptr){
            return 0;
        }
        if(root->val == 0){
            root->val++;
            coins--;
        }
        else if(root->val > 1){
            root->val = 1;
            coins += root->val - 1;
        }
        int left_need = coinsNeed(root->left);
        int right_need = coinsNeed(root->right);
        return coins * (rootToChi(root->left, left_need) + rootToChi(root->right ,right_need));
    }
    int chiToRoot(TreeNode* root){
        
    }
    int distributeCoins(TreeNode* root) {
        
    }
};