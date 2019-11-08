#include<queue>
#include<iostream>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* tempNode = new TreeNode(val);
        if(root == nullptr){
            return tempNode;
        }
        stack<TreeNode*> myStack;
        myStack.push(root);
        while(!myStack.empty()){
            TreeNode* node = myStack.top();
            myStack.pop();
            if(node->val < val && node->right == nullptr){
                node->right = tempNode;
            }
            else if(node->val > val && node->left == nullptr){
                node->left = tempNode;
            }
            else{
                if(node->val < val){
                    myStack.push(node->right);
                }
                else{
                    myStack.push(node->left);
                }
            }
        }
        return root;
    }
};
void printTree(TreeNode* root){
    queue<TreeNode*> treeQueue;
    treeQueue.push(root);
    while(!treeQueue.empty()){
        TreeNode* node = treeQueue.front();
        treeQueue.pop();
        if(node == nullptr){
            cout << "nullptr ";
            continue;
        }
        else{
            cout << node->val << " ";
        }
        treeQueue.push(node->left);
        treeQueue.push(node->right);
    }
    cout << endl;
}
int main(){
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node3 = new TreeNode(3);
    node4->left = node2;
    node4->right = node7;
    node2->left = node1;
    node2->right = node3;
    Solution so;
    TreeNode* result = so.insertIntoBST(node4, 5);
    cout << "done" << endl;
    cout << "The tree is :" << endl;
    printTree(node4);
}