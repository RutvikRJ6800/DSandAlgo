class Solution {
public:
    long long solve(int i, int n, vector<vector<int>>& questions, vector<long long> &dp){
        if(i>=n) return 0;

        // choose non choose
        if(dp[i] != -1) return dp[i];
        return dp[i] = max(questions[i][0] + solve(i+questions[i][1] + 1,n, questions, dp), solve(i+1, n, questions, dp));
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();

        vector<long long> dp(n, -1); 
        return solve(0, n, questions, dp);
    }
};