class Solution {
public:
    int solve(vector<vector<int>>& matrix, vector<vector<int>>& dp, int m, int n, int i, int j){
        if(i<0 || i>=m || j<0 || j>=n) return 1e8;
        if(i==m-1) return matrix[i][j];
        if(dp[i][j] != -1) return dp[i][j];

        dp[i][j] = matrix[i][j] + min(min(solve(matrix, dp, m, n, i+1, j-1), solve(matrix, dp, m, n, i+1, j)), solve(matrix, dp, m, n, i+1, j+1));
        
        return dp[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        /*
        MEMOIZATION
        int m=matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

        int mini = INT_MAX;
        for(int i=0; i<n; i++){
            mini = min(mini, solve(matrix, dp, m, n, 0, i));
        }
        */


        // TABULIZATION
        int m=matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

        for(int i=0; i<n; i++){
            dp[m-1][i] = matrix[m-1][i];
        }

        for(int i=m-2; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(j==n-1){
                    dp[i][j] = matrix[i][j] + min(dp[i+1][j], dp[i+1][j-1]);
                }
                else if(j==0){
                    dp[i][j] = matrix[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
                }
                else{
                    dp[i][j] = matrix[i][j] + min(min(dp[i+1][j-1], dp[i+1][j]), dp[i+1][j+1]);
                }
            }
        }

        int mini = INT_MAX;
        for(int i=0; i<n; i++){
            mini = min(mini, dp[0][i]);
        }
        return mini;
    }
};