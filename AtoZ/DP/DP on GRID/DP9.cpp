class Solution {
public:

    // MEMOIZATION APPROACH
    /*
    int solve(vector<vector<int>>& obstacleGrid, int x, int y, vector<vector<int>> &dp){
        if(x == 0 && y == 0 && obstacleGrid[x][y] != 1) return 1;
        else if(x < 0 || y < 0) return 0;
        else if(obstacleGrid[x][y] == 1) return 0;

        if(dp[x][y] != -1) return dp[x][y];
        int ans = 0;
        ans += solve(obstacleGrid, x-1, y, dp);
        ans += solve(obstacleGrid, x, y-1, dp);
        return dp[x][y] = ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(obstacleGrid, m-1, n-1, dp);
    }*/
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        if(obstacleGrid[0][0] == 1) return 0; // return 0 if obstacle is in the starting cell it self.

        // initialization read leetcode official solution to understand more.
        dp[0][0] = 1;
        for(int i=1; i<m; i++) {
            if(obstacleGrid[i][0] == 1)
                dp[i][0] = 0;
            else{
                dp[i][0] = dp[i-1][0];
            }
        }
        for(int j=1; j<n; j++) {
            if(obstacleGrid[0][j] == 1)
                dp[0][j] = 0;
            else{
                dp[0][j] = dp[0][j-1];
            }
        }

        // table filling
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(obstacleGrid[i][j] != 1){
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        return dp[m-1][n-1];
    }
};