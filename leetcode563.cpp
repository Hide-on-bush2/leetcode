#include<iostream>
#include<cmath>
#include<vector>

using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 
class Solution {
private:
    vector<int> sumOfTree;
public:
    int sumAndTilt(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int sumOfLeft = sumAndTilt(root->left);
        int sumOfRight = sumAndTilt(root->right);
        sumOfTree.push_back(abs(sumOfLeft - sumOfRight));
        return sumOfLeft + sumOfRight + root->val; 
    }
    int findTilt(TreeNode* root) {
        sumAndTilt(root);
        int sum = 0;
        for(int i : sumOfTree){
            sum += i;
        }
        return sum;
    }
};