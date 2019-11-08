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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0){
            return nullptr;
        }
        vector<int> left;
        vector<int> right;
        int tempNum = preorder[0];
        for(int i = 1;i < preorder.size();i++){
            if(preorder[i] > tempNum){
                right.push_back(preorder[i]);
            }
            else{
                left.push_back(preorder[i]);
            }
        }
        TreeNode* tempNode = new TreeNode(tempNum);
        tempNode->left = bstFromPreorder(left);
        tempNode->right = bstFromPreorder(right);
        return tempNode;
    }
};