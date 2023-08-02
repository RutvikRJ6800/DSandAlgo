// https://leetcode.com/problems/edit-distance/

class Solution {
public:
    int solve(int idx2, int idx1, string &word1, string &word2, vector<vector<int>> &dp){
        if(idx2==-1) return idx1+1;
        if(idx1 == -1) return idx2+1;

        if(dp[idx2][idx1] != -1) return dp[idx2][idx1];

        if(word1[idx1] == word2[idx2]){
            dp[idx2][idx1] = solve(idx2-1, idx1-1, word1, word2, dp);
            return dp[idx2][idx1];
        }
        else{
            int case1 = solve(idx2-1, idx1-1, word1, word2, dp); // replace 
            int case2 = solve(idx2-1, idx1, word1, word2, dp);// delete
            int case3 = solve(idx2, idx1-1, word1, word2, dp);// insert

            dp[idx2][idx1] = 1 + min(case1, min(case2, case3));
            return dp[idx2][idx1];
        }
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();

        vector<int> prev(n1+1, 0), curr(n1+1, 0);

        for(int i=0; i<=n1; i++){
            prev[i] = i;
            curr[i] = i;
        }

         for(int  i =1; i<=n2; i++){
            for(int j=1; j<=n1; j++){
                int val1 = prev[j] + 1;
                int val2 = curr[j-1] + 1;
                int val3 = prev[j-1] + (word2[i-1] == word1
                [j-1]? 0 : 1);

                curr[j] = min(val1, min(val2, val3));
            }

            prev = curr;
        }

        return prev[n2];

    }
};