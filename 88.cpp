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
    bool isValidBST(TreeNode* root) {
        nums.clear();
        addelement(root);
        for(int i = 1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                return false;
            }
        }
        return true;
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