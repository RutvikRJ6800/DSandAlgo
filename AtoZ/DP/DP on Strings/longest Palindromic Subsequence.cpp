// https://leetcode.com/problems/longest-palindromic-subsequence/description/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n1 = s.size();
        vector<vector<int>> dp(n1+1, vector<int>(n1+1, 0));

        int maxi = 0;
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n1; j++){
                if(s[i-1] == s[n1-j]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    maxi = max(maxi, dp[i][j]);
                }
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }

        return dp[n1][n1];
    }
};