class Solution {
public:
    /* REC/TOP-DOWN APPROACH
    int solve(string s, string t, int i, int j, vector<vector<int>> &dp){
        if(j==-1){
            return 1;
        }
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]){
            return dp[i][j] = solve(s, t, i-1, j-1, dp) + solve(s, t, i-1, j, dp);
        }
        else{
            return dp[i][j] = solve(s, t, i-1, j, dp);
        }
        // solve(s,t, i, j);
        
    }

    int numDistinct(string s, string t) {
        int ssize = s.size(), tsize = t.size();
        vector<vector<int>> dp(ssize, vector<int>(tsize, -1));

        return solve(s, t , s.size()-1, t.size()-1, dp);
        
    }
    */
    int numDistinct(string s, string t) {
        int ssize = s.size(), tsize = t.size();
        vector<vector<double >> dp(ssize+1, vector<double >(tsize+1, 0));

        for(int i=0; i<ssize+1; i++){
            dp[i][0] = 1;
        }

        for(int i=1; i<=ssize; i++){
            for(int j=1; j<=tsize; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return (int)dp[ssize][tsize];
        
    }
    // space optimization
};