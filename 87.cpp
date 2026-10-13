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
    vector<int>nums;
    int kthSmallest(TreeNode* root, int k) {
        nums.clear();
        addelement(root);
        return nums[k-1];
    }
    void addelement(TreeNode*root){
        if(root->left!=nullptr){
            addelement(root->left);
        }
        nums.push_back(root->val);
        if(root->right!=nullptr){
            addelement(root->right);
        }
    }
};