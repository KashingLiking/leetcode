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
    int sumNumbers(TreeNode* root) {
        int res = 0;
        if(root==nullptr){
            return res;
        }
        queue<TreeNode*>nodes;
        nodes.push(root);
        while(!nodes.empty()){
            TreeNode* cur = nodes.front();
            if(cur->left==nullptr&&cur->right==nullptr){
                res+=cur->val;
            }
            if(cur->left!=nullptr){
                cur->left->val = cur->val*10+cur->left->val;
                nodes.push(cur->left);
            }
            if(cur->right!=nullptr){
                cur->right->val = cur->val*10+cur->right->val;
                nodes.push(cur->right);
            }
            nodes.pop();
        }
        return res;
    }
};