#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int findMaxPosition(int left, int right, vector<int>& nums){
        int temp = -1, index;
        for(int i = left;i < right;i++){
            if(nums[i] > temp){
                temp = nums[i];
                index = i;
            }
        }
        return index;
    }
    TreeNode* maxTree(int left, int right, vector<int>& nums){
        if(left >= right){
            return nullptr;
        }
        int maxIndex = findMaxPosition(left, right, nums);
        TreeNode* tempNode = new TreeNode(nums[maxIndex]);
        tempNode->left = maxTree(left, maxIndex, nums);
        tempNode->right = maxTree(maxIndex + 1, right, nums);
        return tempNode;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return maxTree(0, nums.size(), nums);
    }
};

