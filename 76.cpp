#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr){
            return false;
        }
        queue<TreeNode*>nodes;
        nodes.push(root);
        while(!nodes.empty()){
            int size = nodes.size();
            for(int i = 0;i<size;i++){
                TreeNode* cur = nodes.front();
                if(cur->val==targetSum&&cur->left==nullptr&&cur->right==nullptr){
                    return true;
                }
                if(cur->left!=nullptr){
                    cur->left->val+=cur->val;
                    nodes.push(cur->left);
                }
                if(cur->right!=nullptr){
                    cur->right->val+=cur->val;
                    nodes.push(cur->right);
                }
                nodes.pop();
            }
        }
        return false;
    }
};