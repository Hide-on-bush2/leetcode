#include<cmath>
#include<string>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    vector<string> myResult;
public:
    string getNumber(int x){
        int y = abs(x);
        string str = "";
        while(y != 0){
            str += '0' + y % 10;
            y /= 10;
        }
        if(x < 0){
            str += "-";
        }
        reverse(str.begin(), str.end());
        return str;
    }
    void pathOfTree(TreeNode* root, string str){
        if(root->left == nullptr && root->right == nullptr){
            myResult.push_back(str + getNumber(root->val));
            return;
        }
        if(root->left != nullptr){
            pathOfTree(root->left, str + getNumber(root->val) + "->");
        }
        if(root->right != nullptr){
            pathOfTree(root->right, str + getNumber(root->val) + "->");
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == nullptr){
            return myResult;
        }
        pathOfTree(root, "");
        return myResult;
    }
};