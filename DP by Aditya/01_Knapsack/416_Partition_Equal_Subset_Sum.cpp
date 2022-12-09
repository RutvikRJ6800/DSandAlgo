class Solution {
public:
    /*
    Recursive solution:: 
    bool rec(vector<int>& nums, int n, int sum){
        if(sum == 0) return true;
        if(n == 0 && sum != 0) return false;
        
        if(nums[n-1] <= sum){
            // two choice
            return (rec(nums, n-1, sum - nums[n-1]) || rec(nums, n-1, sum));
        }
        else // single choice
           return  rec(nums, n-1, sum);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int i=0; i<n; i++){
            total += nums[i];
        }
        
        if(total % 2 == 1) return false; // odd total
        
        int target = total / 2;
        
        return rec(nums, n, target);
    } */

    //  MEMOISATION APPROACH
    /*
    bool rec(vector<int>& nums, int n, int sum, vector<vector<int>> &dp){
        if(sum == 0) return true;
        if(n == 0 && sum != 0) return false;
        
        // check if solution is already calculated
        if(dp[n][sum] != -1) return dp[n][sum];
        if(nums[n-1] <= sum){
            // two choice
            dp[n][sum] = (rec(nums, n-1, sum - nums[n-1], dp) || rec(nums, n-1, sum, dp));
            return dp[n][sum];
        }
        else{    
        // single choice
           dp[n][sum] = rec(nums, n-1, sum, dp);
           return  dp[n][sum];
        } 
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int i=0; i<n; i++){
            total += nums[i];
        }
        
        if(total % 2 == 1) return false; // odd total
        
        int target = total / 2;
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        
        return rec(nums, n, target, dp);
    }
    */

   // TOP - DOWN APPROACH
   bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int i=0; i<n; i++){
            total += nums[i];
        }
        
        if(total % 2 == 1) return false; // odd total
        
        int target = total / 2;
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        
        for(int i=0; i<n+1; i++){
            dp[i][0] = 1;
        }
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<target+1; j++){
                if(nums[i-1] <= j){
                    // two choice
                    dp[i][j] = (dp[i-1][j - nums[i-1]] || dp[i-1][j]);
                }
                else{    
                // single choice
                   dp[i][j] = dp[i-1][j];
                } 
            }
        }
        
        return dp[n][target];
    }
};