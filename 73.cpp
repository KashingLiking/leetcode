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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty()){
            return nullptr;
        }
        TreeNode* root = new TreeNode(postorder[postorder.size()-1]);
        int sig = 0;
        for(;sig<inorder.size();sig++){
            if(inorder[sig]==postorder[postorder.size()-1]){
                break;
            }
        }
        vector<int>leftin(inorder.begin(),inorder.begin()+sig);
        vector<int>rightin(inorder.begin()+sig+1,inorder.end());
        vector<int>leftpos(postorder.begin(),postorder.begin()+sig);
        vector<int>rightpos(postorder.begin()+sig,postorder.end()-1);

        root->left = buildTree(leftin,leftpos);
        root->right = buildTree(rightin,rightpos);

        return root;
    }
};