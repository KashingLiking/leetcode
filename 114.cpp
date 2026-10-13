#include<iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = 0,res = nums[0];
        for(int i = 0;i<nums.size();i++){
            cur+=nums[i];
            res = max(cur,res);
            if(cur<0){
                cur = 0;
            }
        }
        return res;
    }
};