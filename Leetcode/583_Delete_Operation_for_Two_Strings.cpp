// https://leetcode.com/problems/delete-operation-for-two-strings/description/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();

        vector<vector<int>> dp(n1+1, vector<int>(n2+1,0));

        // lcs find
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        // n1 -  dp[n1][n2] deletions for word1 ---> LCS
        // n2 -  dp[n1][n2] deletions for word2 ---> LCS
        
        // so total n1 + n2 - 2*dp[n1][n2] for making word1 and word2 to lcs 
        return n1+n2-2*dp[n1][n2];
    }
};