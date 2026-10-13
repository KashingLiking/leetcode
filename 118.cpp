#include<iostream>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        int left = 0, right = nums.size()-1,mid = 0;
        while(left<=right){
            mid = (left+right)/2;
            if(mid==0){
                if(nums[mid+1]<nums[mid]){
                    return mid;
                }else{
                    left = mid + 1;
                }
            }else if(mid==nums.size()-1){
                if(nums[mid-1]<nums[mid]){
                    return mid;
                }else{
                    right = mid -1;
                }
            }else{
                if(nums[mid-1]<nums[mid]&&nums[mid+1]<nums[mid]){
                    return mid;
                }else{
                    if(nums[mid-1]>nums[mid]){
                        right = mid -1;
                    }else{
                        left = mid + 1;
                    }
                }
            }
        }
        return mid;
    }
};