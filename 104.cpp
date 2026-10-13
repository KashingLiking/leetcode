#include<iostream>
using namespace std;

class Solution {
public:
    vector<int>path;
    vector<vector<int>>res;
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums);
        return res;
    }
    void dfs(vector<int>leftnum){
        if(leftnum.size()==0){
            res.push_back(path);
        }else{
            for(int i = 0;i<leftnum.size();i++){
                path.push_back(leftnum[i]);
                vector<int> next = leftnum;
                next.erase(next.begin() + i);
                dfs(next);
                path.pop_back();
            }
        }
    }
};