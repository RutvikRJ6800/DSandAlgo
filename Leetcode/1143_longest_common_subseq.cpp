class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int size1, size2;
        size1= text1.size();
        size2 = text2.size();
        
        vector<vector<int>> dp(size1+1, vector<int>(size2+1, 0));
        
        for(int i=1; i<size1+1; i++){ // asume index sifting (text1[0] at i=1) and (text2[0] at j=1)
            for(int j=1; j<size2+1; j++){
                if(text1[i-1] == text2[j-1]){ // if both char is equal 1 + diagonal entry
                    dp[i][j] = 1+dp[i-1][j-1]; // 1 + matching (text1[0,i-1] to text2[0,j-1])
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]); // max of matching of (text1[0:i-1] and text2[0:j]) or (text1[0:i] and text2[0:j-1])
                }
            }
        }
        
        return dp[size1][size2];
    }
};