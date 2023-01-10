// https://leetcode.com/problems/triangle/description/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int ans = triangle[0][0];
        int m = triangle.size();
        int n = triangle[m-1].size();

        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[0][0] = triangle[0][0];

        for(int i=1; i<n; i++){
            dp[i][0] = dp[i-1][0] + triangle[i][0];
        }
        
        for(int i=1; i<m; i++){

            for(int j=1; j<=i; j++){
                dp[i][j] = triangle[i][j] + min(dp[i-1][j-1], dp[i-1][j]);
            }
    
        }

        int mini = INT_MAX;
        for(int i=0; i<n; i++){
            mini = min(mini, dp[m-1][i]);
        }

        return mini;

        
    }
};