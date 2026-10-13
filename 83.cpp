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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>res;
        if(root == nullptr){
            return res;
        }
        queue<TreeNode*>nodes;
        nodes.push(root);
        while(!nodes.empty()){
            double sum = 0;
            int size = nodes.size();
            for(int i = 0;i<size;i++){
                TreeNode* cur = nodes.front();
                sum+=cur->val;
                if(cur->left!=nullptr){
                    nodes.push(cur->left);
                }
                if(cur->right!=nullptr){
                    nodes.push(cur->right);
                }
                nodes.pop();
            }
            res.push_back(sum/size);
        }
        return res;
    }
};