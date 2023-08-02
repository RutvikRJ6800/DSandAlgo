// https://leetcode.com/problems/burst-balloons/description/

class Solution {
public:
    int solve(vector<int>& nums, int i, int j, vector<vector<int>> &dp){
        if(i>j) return 0;
        // if(i==j) return nums[i];
        if(dp[i][j] != -1) return dp[i][j];

        int ans = INT_MIN;

        for(int k=i; k<=j; k++){
            int curr = nums[i-1]*nums[j+1]*nums[k] + solve(nums, i, k-1, dp) + solve(nums, k+1, j, dp);
            ans = max(ans, curr);
        }

        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        /*
        MEMOIZATION
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(nums, 1, n, dp);
*/
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for(int i=n; i>=1; i--){
            for(int j=i; j<=n; j++){
                int ans = INT_MIN;

                for(int k=i; k<=j; k++){
                    int curr = nums[i-1]*nums[j+1]*nums[k] + dp[i][k-1] + dp[k+1][j];
                    ans = max(ans, curr);
                }

                dp[i][j] = ans;
            }
        }

        return dp[1][n];
    }
};