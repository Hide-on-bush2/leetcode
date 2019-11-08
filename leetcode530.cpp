#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 
class Solution {
private:
    vector<int> tempOfDifference;
    stack<TreeNode*> myStack;
public:
    int findMinOfRight(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        while(root->left != nullptr){
            root = root->left;
        }
        return root->val;
    }
    int findMaxOfLeft(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        while(root->right != nullptr){
            root = root->right;
        }
        return root->val;
    }
    int getMinimumDifference(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        myStack.push(root);
        while(!myStack.empty()){
            TreeNode* tempNode = myStack.top();
            myStack.pop();
            cout << tempNode->val << "be pop of stack\n";
            int oneOfResult;
            if(tempNode->left == nullptr && tempNode->right == nullptr){
                continue;
            }
            else if(tempNode->left == nullptr && tempNode->right != nullptr){
                oneOfResult = abs(tempNode->val - findMinOfRight(tempNode->right));
            }
            else if(tempNode->right == nullptr && tempNode->left != nullptr){
                oneOfResult = abs(tempNode->val - findMaxOfLeft(tempNode->left));
            }
            else{
                oneOfResult = abs(tempNode->val - findMinOfRight(tempNode->right)) < abs(tempNode->val - findMaxOfLeft(tempNode->left)) ? abs(tempNode->val - findMinOfRight(tempNode->right)) : abs(tempNode->val - findMaxOfLeft(tempNode->left));
            }
            tempOfDifference.push_back(oneOfResult);
            cout << oneOfResult << "be pushed" << endl;
            if(tempNode->left != nullptr){
                cout << tempNode->left->val << "be pushed in stack\n";
                myStack.push(tempNode->left);
            }
            if(tempNode->right != nullptr){
                cout << tempNode->right->val << "be pushed in stack\n";
                myStack.push(tempNode->right);
            }
        }
        vector<int>::iterator pr = min_element(tempOfDifference.begin(), tempOfDifference.end());
        return *pr;
    }
};

int main(){
    TreeNode* Node543 = new TreeNode(543);
    TreeNode* Node384 = new TreeNode(384);
    TreeNode* Node652 = new TreeNode(652);
    TreeNode* Node445 = new TreeNode(445);
    TreeNode* Node699 = new TreeNode(699);
    Node543->left = Node384;
    Node543->right = Node652;
    Node384->right = Node445;
    Node652->right = Node699;
    cout << "start: " << endl;
    Solution so;
    cout << "The answer is " << so.getMinimumDifference(Node543) << endl;
}