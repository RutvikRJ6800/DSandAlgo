class Solution {
public:
    int solve(int i, int &zero, int &one, vector<int> &dp){
        if(i == 0) return 1;
        else if(i < 0) return 0;

        if(dp[i] != -1) return dp[i];

        return dp[i] = (solve(i-one, zero, one, dp) + solve(i-zero, zero, one, dp)) % (1000000007);

    }
    int countGoodStrings(int low, int high, int zero, int one) {
        int ans = 0;
        vector<int> dp(high+1, -1);
        for(int i=low; i<=high; i++){
            // cout<<i<<endl;
            ans  = (ans + solve(i,zero, one, dp)) % (1000000007);
        }
        return ans;
    }
};