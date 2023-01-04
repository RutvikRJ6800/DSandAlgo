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
    int solve(int x, int y, vector<vector<int>> &dp){
        if(x==0 && y == 0) return 1;
        if(x<0 || y<0) return 0;

        if(dp[x][y] != -1) return dp[x][y];

        int ans = 0;
        ans += solve(x, y-1, dp);
        ans += solve(x-1, y, dp);

        return dp[x][y] = ans;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(m-1, n-1, dp);
    }*/


    // BOTTOMO - UP APPROACH
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i=0; i<m; i++) dp[i][0] = 1;
        for(int j=0; j<n; j++) dp[0][j] = 1;

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }

    // we can do this que using combinatorics in just constant time.
    
};