class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int size1 = word1.size();
        int size2 = word2.size();
        
        vector<vector<int>> dp(size1+1, vector<int>(size2+1, 0));
        
        for(int i=0; i<size1+1; i++) dp[i][0] = i;
        for(int i=0; i<size2+1; i++) dp[0][i] = i;
        
        for(int i=1; i<size1+1; i++){
            for(int j=1; j<size2+1; j++){
                // check if char is matching
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = 0 + dp[i-1][j-1];
                }
                else{
                    // char not matching in all string so consider 3 cases
                    // case1: add char in string 1 and check further
                    // case2: add char in string 2 and check further
                    // case3: replace char in string 2 as it is in string2
                    // all above cases denote one editing so +1 is there.
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                }
            }
        }
        
        return dp[size1][size2];
        
    }
};