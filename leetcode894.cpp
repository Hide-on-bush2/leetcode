#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* clone(TreeNode* root){//复制树
        TreeNode* new_root = new TreeNode(0);
        new_root->left = (root->left) ? clone(root->left) : nullptr;
        new_root->right = (root->right) ? clone(root->right) : nullptr;
        return new_root;
    }
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> ret;
        if(N == 1){//只有一个节点时直接存储
            ret.push_back(new TreeNode(0));
        }
        else if(N % 2){//处理节点树为奇数的情况，节点为偶数的不可能符合要求
            for(int i = 2;i <= N;i += 2){
                auto left = allPossibleFBT(i - 1);
                auto right = allPossibleFBT(N - i);//递归，将N个节点分配到左子树和右子树，返回的是存储的数组，这里保证了递归到两个子树的节点个数一定为奇数个
                for(int l_idx = 0;l_idx < left.size();l_idx++){
                    for(int r_idx = 0 ;r_idx < right.size();r_idx++){//将当前节点连上可能的左右子树然后放进数组中
                        ret.push_back(new TreeNode(0));
                        ret.back()->left = (r_idx == right.size() - 1) ? left[l_idx] : clone(left[l_idx]);
                        ret.back()->right = (l_idx == left.size() - 1) ? right[r_idx] : clone(right[r_idx]);
                    }
                }
            }
        }
        return ret;
    }
};