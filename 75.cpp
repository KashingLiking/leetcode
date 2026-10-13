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
    void flatten(TreeNode* root) {
        if(root==nullptr){
            return;
        }
        queue<TreeNode*>nodes;
        addelement(root,nodes);
        TreeNode* prev = nullptr;
        while(!nodes.empty()){
            TreeNode* cur = nodes.front();
            nodes.pop();
            if(prev!=nullptr){
                prev->left = nullptr;
                prev->right = cur;
            }
            prev = cur;
        }
        prev->left = nullptr;
        prev->right = nullptr;
        return;
    }
    void addelement(TreeNode* root,queue<TreeNode*>&nodes){
        nodes.push(root);
        if(root->left!=nullptr){
            addelement(root->left,nodes);
        }
        if(root->right!=nullptr){
            addelement(root->right,nodes);
        }
    }
};