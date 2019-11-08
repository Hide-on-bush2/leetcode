#include<queue>
#include<utility>
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
    int findIndex(vector< pair<int, int> >& tempV, int val){
        for(int i = 0;i < tempV.size();i++){
            if(tempV[i].first == val){
                return i;
            }
        }
        return -1;
    }
    int findMaxTims(vector< pair<int, int> >& tempV){
        int times = 0;
        for(int i = 0;i < tempV.size();i++){
            if(tempV[i].second > times){
                times = tempV[i].second;
            }
        }
        return times;
    }
    int addSubTree(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        return root->val + addSubTree(root->left) + addSubTree(root->right);
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector< pair<int, int> > tempV;
        vector<int> myResult;
        queue<TreeNode*> myQueue;
        if(root == nullptr){
            return myResult;;
        }
        myQueue.push(root);
        while(!myQueue.empty()){
            TreeNode* tempNode = myQueue.front();
            myQueue.pop();
            int tempSum = addSubTree(tempNode);
            int index = findIndex(tempV, tempSum);
            if(index == -1){
                tempV.push_back(make_pair(tempSum, 1));
            }
            else{
                tempV[index].second += 1;
            }
            if(tempNode->left != nullptr){
                myQueue.push(tempNode->left);
            }
            if(tempNode->right != nullptr){
                myQueue.push(tempNode->right);
            }
        }
        int maxTimes = findMaxTims(tempV);
        for(int i = 0;i < tempV.size();i++){
            if(tempV[i].second == maxTimes){
                myResult.push_back(tempV[i].first);
            }
        }
        return myResult;
    }
};