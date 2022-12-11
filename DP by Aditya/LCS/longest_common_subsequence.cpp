// https://leetcode.com/problems/longest-common-subsequence/description/
class Solution {
public:
    // RECURSIVE APPROACH
    // int longestCommonSubsequence(string text1, string text2) {
    //     int n1 = text1.size();
    //     int n2 = text2.size();

    //     if(n1 == 0 || n2 == 0) return 0;

    //     string newt1 = text1.substr (0,n1-1);
    //     string newt2 = text2.substr (0,n2-1);

    //     if(text1[n1-1] == text2[n2-1]){
    //         return 1+ longestCommonSubsequence(newt1, newt2);
    //     }

    //     return max(longestCommonSubsequence(newt1, text2), longestCommonSubsequence(text1, newt2));
    // }

    // MEMOISATION APPROACH
    /*
    int helper(string text1, string text2, vector<vector<int>> &dp) {
        int n1 = text1.size();
        int n2 = text2.size();

        if(n1 == 0 || n2 == 0) return 0;


        if(dp[n1][n2] != -1) return dp[n1][n2];

        string newt1 = text1.substr (0,n1-1);
        string newt2 = text2.substr (0,n2-1);

        if(text1[n1-1] == text2[n2-1]){
            dp[n1][n2] = 1+ helper(newt1, newt2, dp);
            return dp[n1][n2];
        }

        dp[n1][n2] = max(helper(newt1, text2, dp), helper(text1, newt2, dp));
        return dp[n1][n2];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();

        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));

        return helper(text1, text2, dp);

        
    }
    */

   // TOP DOWN APPROACH
   int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();

        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

        for(int i=1; i<n1+1; i++){
            for(int j=1; j<n2+1; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }

        
        return dp[n1][n2];

        
    }

};