#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>>res;
    vector<int>path;
    vector<vector<int>> combine(int n, int k) {
        dfs(1,n,k);
        return res;
    }
    void dfs(int start,int n,int k){
        if(path.size()==k){
            res.push_back(path);
            return;
        }
        if(start>n){
            return;
        }else{
            for(int i = start;i<=n;i++){
                path.push_back(i);

                dfs(i+1,n,k);

                path.pop_back();
            }
        }
    }
};