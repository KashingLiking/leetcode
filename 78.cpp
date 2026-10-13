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
//     int maxPathSum(TreeNode* root) {
//         int maxres = 0;
//         queue<TreeNode*>nodes;
//         nodes.push(root);
//         while(!nodes.empty()){
//             TreeNode* cur = nodes.front();
//             maxres = max(maxres,cur->val);
//             if(cur->left!=nullptr){
//                 if(cur->val>0){
//                     cur->left->val+=cur->val;
//                 }
//                 nodes.push(cur->left);
//             }
//             if(cur->right!=nullptr){
//                 if(cur->val>0){
//                     cur->right->val+=cur->val;
//                 }
//                 nodes.push(cur->right);
//             }
//             nodes.pop();
//         }
//         return maxres;
//     }
// };理解错了

class Solution {
public:
    int ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
        Depth(root);
        return ans;
    }
    int Depth(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int left = max(0,Depth(root->left));
        int right = max(0,Depth(root->right));

        ans = max(ans,root->val+left+right);

        return root->val+max(left,right);
    }
};