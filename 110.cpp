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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0){
            return nullptr;
        }
        TreeNode* node = new TreeNode();
        if(nums.size()==1){
            node->val = nums[0];
        }
        if(nums.size()>1){
            node->val = nums[nums.size()/2];
            vector<int>left(nums.begin(),nums.begin()+nums.size()/2);
            vector<int>right(nums.begin()+nums.size()/2+1,nums.begin()+nums.size());
            node->left = sortedArrayToBST(left);
            node->right = sortedArrayToBST(right);
        }
        return node;
    }
};