class Solution {
public:

    // MEMOIZATION APPROACH
    /*
    int solve(int &m, int &n, int i, int j, vector<vector<int>> &dp, vector<vector<int>>& grid){
        if(i==m-1 && j==n-1) return 1;
        if(i<0 || i>=m || j<0 || j>=n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(grid[i][j] == 1) return 0;

        return dp[i][j] = solve(m, n, i+1, j, dp, grid) + solve(m, n, i, j+1, dp,  grid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        MEMOIZATION APPROACH
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] == 1) return 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(m, n, 0, 0, dp, obstacleGrid);
    }*/
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        // TABULIZATION
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] == 1) return 0;  // return 0 if obstacle is in the starting cell it self.
        
        // initialization read leetcode official solution to understand more.
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[m-1][n] = 1;
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }
                else
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};