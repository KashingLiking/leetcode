#include<iostream>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>qp;
        for(int i = 0;i<k;i++){
            qp.push(nums[i]);
        }
        for(int i = k;i<nums.size();i++){
            if(nums[i]>qp.top()){
                qp.push(nums[i]);
                qp.pop();
            }
        }
        return qp.top();
    }
};