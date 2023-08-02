// https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), lis = 0, maxCount=0;

        vector<int> dp(n, 1), count(n,1);

        for(int i=0; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(nums[i] > nums[j] && 1 + dp[j] > dp[i]){
                    dp[i] = 1 + dp[j];
                    count[i] = count[j];
                }
                else if(nums[i] > nums[j] && 1 + dp[j] == dp[i]){
                    count[i] += count[j];
                }
            }
            if(lis<dp[i]){
                lis = dp[i];
                maxCount = count[i];
            }
            else if(lis == dp[i]){
                maxCount += count[i];
            }
        }
        return maxCount;
    }
};