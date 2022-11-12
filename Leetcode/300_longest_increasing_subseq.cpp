class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        
        for(int i=1; i<n; i++){
            int num = nums[i];
            int maxseen = 0;
            
            for(int j = i-1; j>=0; j--){
                if(num > nums[j] && maxseen < dp[j]) maxseen = dp[j];
            }
            
            dp[i] = maxseen+1;
        }
        
        for(int i=0; i<n; i++){
            cout<<dp[i]<<", ";
        }
        
        
        int intMin = INT_MIN;
        for(int i=0; i<n; i++){
            if(intMin < dp[i]) intMin = dp[i];
        }
        
        return intMin;
    }
};