#include<algorithm>
#include<queue>
#include<string>
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
    int coinsNeed(TreeNode* root){//该树需要的硬币数
        if(root == nullptr){
            return 0;
        }
        return 1 - root->val + coinsNeed(root->left) + coinsNeed(root->right); 
    }
    int rootToChi(TreeNode* root, TreeNode* children, int coinsNeed){//将根节点多余的硬币移动到子树
        if(root == nullptr || children == nullptr){
            return 0;
        }
        children->val += coinsNeed;
        root->val -= coinsNeed;
        return coinsNeed;
    }
    int chiToRoot(TreeNode* root, int coins){//将子树中多余的硬币移动到根节点
        if(root == nullptr || coins <= 0){
            return 0;
        }
        if(root->val >= coins){
            root->val -= coins;
            return coins;
        }
        int tempCoins = 0;
        if(root->val > 0){
            coins -= root->val;
            tempCoins = root->val;
            root->val = 0;
        }
        int left_has = - coinsNeed(root->left);
        if(left_has >= coins){
            return chiToRoot(root->left, coins) + coins + tempCoins;
        }
        int right_has = - coinsNeed(root->right) > coins ? coins : -coinsNeed(root->right);
        return chiToRoot(root->left, coins - right_has) + chiToRoot(root->right, right_has) + coins + tempCoins; 
    }
    int distributeCoins(TreeNode* root) {
        int result = 0;
        if(root == nullptr){
            return result;
        }
        int left_need = coinsNeed(root->left);
        int right_need = coinsNeed(root->right);
        if(left_need < 0){
            result += chiToRoot(root->left, -left_need);
            root->val -= left_need;
        }
        if(right_need < 0){
            result += chiToRoot(root->right, -right_need);
            root->val -= right_need;
        }
        if(left_need > 0){
            result += rootToChi(root, root->left, left_need);
        }
        if(right_need > 0){
            result += rootToChi(root, root->right, right_need);
        }
        return result + distributeCoins(root->left) + distributeCoins(root->right);
    }
};




TreeNode* createTree(vector<string> vec){
    if(vec.size() == 0){
        return nullptr;
    }
    string str = vec.back();
    if(str == "null"){
        return nullptr;
    }
    TreeNode* tempTree = new TreeNode(str[0] - '0');
    vec.pop_back();
    tempTree->left = createTree(vec);
    if(vec.size() < 2){
        tempTree->left = createTree(vec);
        return tempTree;
    }
    string tempLeft = vec.back();
    vec.pop_back();
    string tempRight = vec.back();
    vec.pop_back();
    vec.push_back(tempLeft);
    tempTree->left = createTree(vec);
    vec.pop_back();
    vec.push_back(tempRight);
    tempTree->right = createTree(vec);
    return tempTree;
}
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
    vector<string> vec;
    string str = " ";
    do{
        cout << "string: <'done' to quit>";
        cin >> str;
        vec.push_back(str);
    }while(str != "done");
    vec.pop_back();
    reverse(vec.begin(), vec.end());
    TreeNode* tree = createTree(vec);
    printTree(tree);
    cout << "done" << endl;
    return 0;
}