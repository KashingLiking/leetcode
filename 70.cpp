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
//     TreeNode* invertTree(TreeNode* root) {
//         if(root==nullptr){
//             return root;
//         }
//         if(root->left==nullptr&&root->right==nullptr){
//             return root;
//         }else if(root->left!=nullptr&&root->right!=nullptr){
//             TreeNode* mid = root->left;
//             root->left = root->right;
//             root->right = mid;
//             invertTree(root->left);
//             invertTree(root->right);
//         }else if(root->left==nullptr){
//             root->left = root->right;
//             root->right = nullptr;
//             invertTree(root->left);
//         }else if(root->right == nullptr){
//             root->right = root->left;
//             root->left = nullptr;
//             invertTree(root->right);
//         }
//         return root;
//     }
// };

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr){
            return nullptr;
        }

        TreeNode* mid = root->left; 
        root->left = root->right;
        root->right = mid;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};