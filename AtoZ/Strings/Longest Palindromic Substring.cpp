class Solution {
// https://leetcode.com/problems/longest-palindromic-substring/description/
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i=0; i<n; i++){
           dp[i][i] = 1;
        }   

        string maxString (1, s[0]);
        for(int len=2; len<=n; len++){
           for(int start=0; start<= n - len; start++){
               int end = start + (len - 1);

               if(s[start] == s[end] && (dp[start + 1][end - 1])){
                   dp[start][end] = 1;
                    maxString = s.substr(start, len);
               }
               else{
                   dp[start][end] = 0;
               }
           }
        }

        return maxString;
    }
};