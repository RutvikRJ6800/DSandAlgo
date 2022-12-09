class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        int n=nums.size();
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }
        if((sum+target)%2!=0 || (abs(target)>sum) )return 0;
        
        int s1=(target+sum)/2;
        vector<vector<int>> dp(n+1,vector<int>(s1+1,0));
        
        for(int i=0; i<n+1; i++){
            dp[i][0]=1;
        }
        
        for(int i=1; i<n+1; i++){
            for(int j=0; j<s1+1; j++){
                if(nums[i-1]<=j){
                    dp[i][j]=(dp[i-1][j-nums[i-1]]+dp[i-1][j]);
                }
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][s1];
        
        
    }
};