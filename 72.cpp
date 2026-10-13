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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        int sig = 0;
        for(;sig<inorder.size();sig++){
            if(inorder[sig]==preorder[0]){
                break;
            }
        }
        vector<int>leftpre(preorder.begin()+1,preorder.begin()+1+sig);
        vector<int>rightpre(preorder.begin()+1+sig,preorder.end());
        vector<int>leftin(inorder.begin(),inorder.begin()+sig);
        vector<int>rightin(inorder.begin()+sig+1,inorder.end());
        root->left = buildTree(leftpre,leftin);
        root->right = buildTree(rightpre,rightin);

        return root;
    }
};