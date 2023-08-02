// https://leetcode.com/problems/minimum-path-sum/description/
class Solution {
public:
    int solve(int &m, int &n, int i, int j, vector<vector<int>> &dp, vector<vector<int>>& grid){
        if(i==m-1 && j==n-1) return grid[i][j];
        if(i<0 || i>=m || j<0 || j>=n) return 1e8;
        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = grid[i][j] + min(solve(m, n, i+1, j, dp, grid) , solve(m, n, i, j+1, dp,  grid));
    }
    int minPathSum(vector<vector<int>>& grid) {

         /*
        MEMOIZATION APPROACH
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(m, n, 0, 0, dp, grid);
        */

        // TABULIZATION
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int sum = 0;
        for(int i=n-1; i>=0; i--){
            sum = sum + grid[m-1][i];
            dp[m-1][i] = sum;
        }

        for(int i=0; i<m; i++){
            dp[i][n] = INT_MAX;
        }

        for(int i=m-2; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                dp[i][j] = grid[i][j] + min(dp[i+1][j], dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};