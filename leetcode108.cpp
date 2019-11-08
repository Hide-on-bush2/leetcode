#include<vector>
#include<iostream>
using std::vector;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 
class Solution {
public:
    TreeNode* bsfInsert(vector<int>& tempV, int left, int right){
        if(left >= right){
            return nullptr;
        }
        int mid = (left + right) / 2;
        TreeNode* tempTree = new TreeNode(tempV[mid]);
        tempTree->left = bsfInsert(tempV, left, mid);
        tempTree->right = bsfInsert(tempV, mid + 1, right);
        return tempTree;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return bsfInsert(nums, 0, nums.size());
    }
};