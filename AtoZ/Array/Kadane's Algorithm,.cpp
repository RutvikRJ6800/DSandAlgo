// https://leetcode.com/problems/maximum-subarray/description/
class Solution {
public:
    int solve(vector<int> &nums, int left, int right){
        if(left > right) return INT_MIN;
        if(left == right) return nums[left];

        int mid = left + (right-left)/2;
        int leftSubArraySum = solve(nums, left, mid);
        int rightSubArraySum = solve(nums, mid+1, right);

        int leftMax = INT_MIN;
        for(int i=mid, sum=0; i>=left; i--){
            sum += nums[i];
            leftMax = max(leftMax, sum);
        }

        int rightMax = INT_MIN;
        for(int i=mid+1, sum=0; i<=right; i++){
            sum += nums[i];
            rightMax = max(rightMax, sum);
        }

        return max(leftSubArraySum, max(rightSubArraySum, leftMax + rightMax));

    }
    int maxSubArray(vector<int>& nums) {
        // O(N) time and O(1) Space :: Kaden's Algo
        /*
        int currSum = nums[0], maxSum = nums[0];
        
        for(int i=1; i<nums.size(); i++){
            if(currSum < 0) currSum = 0;
            currSum += nums[i];
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
        */

        // D & C approach
        return solve(nums, 0, nums.size()-1);
    }
};