// https://leetcode.com/problems/distinct-subsequences/

class Solution {
public:
    int numDistinct(string s, string t) {
        int n1 = s.size(), n2 = t.size();

        vector<vector<double>> dp(n2+1, vector<double>(n1+1, 0));
        for(int i=0; i<=n1; i++){
            dp[0][i] = 1;
        }
        for(int i=1; i<=n2; i++){
            for(int j=1; j<=n1; j++){
                if(s[j-1] == t[i-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                }
                else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }

        return dp[n2][n1];
    }
};