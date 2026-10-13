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

// class Solution {
// public:
//     int mindif = 0;
//     int getMinimumDifference(TreeNode* root) {
//         mindif = INT_MAX;
//         difference(root);
//         return mindif;
//     }
//     void difference(TreeNode*root){
//         if(root->left!=nullptr){
//             mindif = min(mindif,root->val-root->left->val);
//             difference(root->left);
//         }
//         if(root->right!=nullptr){
//             mindif = min(mindif,root->right->val-root->val);
//             difference(root->right);
//         }
//     }
// };搞错了

class Solution {
public:
    vector<int>nums;
    int getMinimumDifference(TreeNode* root) {
        int mindif = INT_MAX;
        nums.clear();
        addelement(root);
        for(int i = 1;i<nums.size();i++){
            mindif = min(mindif,nums[i]-nums[i-1]);
        }
        return mindif;
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