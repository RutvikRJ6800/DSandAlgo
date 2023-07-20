// https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
      
        int i=0, j=nums.size()-1, mid = 0, cmp = 0;

        while(i<j){
            mid = i + (j-i)/2;
            cmp = (mid%2 == 0)?mid+1:mid-1;
            if(nums[mid] == nums[cmp]) i = mid+1;
            else{
                j = mid;
            }
        }
        return nums[j];
    }
};