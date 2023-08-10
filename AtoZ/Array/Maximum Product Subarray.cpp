// https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxTillNow = nums[0];
        int prevMin = nums[0];
        int prevMax = nums[0];

        for(int i=1; i<nums.size(); i++){
            int currMax = max(max(nums[i],prevMin*nums[i]), prevMax*nums[i]);
            int currMin = min(min(nums[i],prevMin*nums[i]), prevMax*nums[i]);

            prevMin = currMin;
            prevMax = currMax;
            
            maxTillNow = max(maxTillNow, currMax);
        }
        return maxTillNow;
    }
};