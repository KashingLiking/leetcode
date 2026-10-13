#include<iostream>
using namespace std;
#include<unordered_set>

class Solution {
public:
    vector<vector<int>>res;
    vector<int>path;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res.clear();
        dfs(target,candidates);
        return res;
    }
    void dfs(int left,vector<int>candidates){
        if(left==0){
            res.push_back(path);
            return;
        }else if(left<0){
            return;
        }else{
            for(int i = 0;i<candidates.size();i++){
                path.push_back(candidates[i]);
                vector<int>copy = candidates;
                copy.erase(copy.begin(),copy.begin()+i);
                dfs(left-candidates[i],copy);
                path.pop_back();
            }
        }
        return;
    }
};