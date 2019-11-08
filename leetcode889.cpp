#include<vector>
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
    int findIndex(vector<int>& vec, int val){
        for(int i = 0;i < vec.size();i++){
            if(vec[i] == val){
                return i;
            }
        }
        return -1;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if(pre.size() == 0){
            return nullptr;
        }
        TreeNode* tempNode = new TreeNode(pre[0]);
        if(pre.size() == 1){
            return tempNode;
        }
        int index = findIndex(post, pre[1]);
        vector<int> leftPre(pre.begin() + 1, pre.begin() + 2 + index);
        vector<int> leftPost(post.begin(), post.begin() + index + 1);
        vector<int> rightPre(pre.begin() + index + 2, pre.end());
        vector<int> rightPost(post.begin() + index + 1, post.end() - 1);
        tempNode->left = constructFromPrePost(leftPre, leftPost);
        tempNode->right = constructFromPrePost(rightPre, rightPost);
        return tempNode;
    }
};