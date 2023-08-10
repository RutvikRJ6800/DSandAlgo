// https://leetcode.com/problems/move-zeroes/description/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=-1, n = nums.size(),j=0;
        if(n==1) return;
        while(j<n){
            if(nums[j] != 0){
                i++;
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
            j++;
        }
    }
};