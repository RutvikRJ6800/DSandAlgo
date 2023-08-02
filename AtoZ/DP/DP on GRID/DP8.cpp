// https://leetcode.com/problems/unique-paths/description/
class Solution {
public:
    /*
    RECURSIVE SOLUTION
    int solve(int x, int y){
        if(x==0 && y == 0) return 1;
        if(x<0 || y<0) return 0;

        int ans = 0;
        ans += solve(x, y-1);
        ans += solve(x-1, y);

        return ans;
    }
    int uniquePaths(int m, int n) {
        return solve(m-1, n-1);
    }
    */

    // MEMOIZATION APPROACH
    /*
    int solve(int &m, int &n, int i, int j, vector<vector<int>> &dp){
        if(i==m-1 && j==n-1) return 1;
        if(i<0 || i>m || j<0 || j>n) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = solve(m, n, i+1, j, dp) + solve(m, n, i, j+1, dp);
    }
    int uniquePaths(int m, int n) {
        MEMOIZATION APPROACH
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(m, n, 0, 0, dp);
    }*/


    // BOTTOMO - UP APPROACH
    int uniquePaths(int m, int n) {

        // TABULIZATION
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[m-1][n] = 1;
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];
    }

    // we can do this que using combinatorics in just constant time.
    
};