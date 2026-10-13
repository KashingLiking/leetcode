#include<iostream>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int left = 0, right = nums.size()-1,mid = 0;
        while(left<right){
            if(right - left == 1){
                return min(nums[left],nums[right]);
            }else{
                mid = (left+right)/2;
                if(nums[mid]>nums[left]&&nums[mid]>nums[right]){
                    left = mid + 1;
                }else{
                    right = mid;
                }
            }
        }
        return nums[mid];
    }
};