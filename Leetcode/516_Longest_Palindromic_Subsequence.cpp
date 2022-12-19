class Solution {
public:
    // RECURSIVE APPROACH
    /* int ans = 0;
    bool isPalindrome(string s){
        int i=0;
        int j = s.size() - 1;

        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;
    }
    void rec(string s, string prev, int i){
        if(i == 0){
            if(isPalindrome(prev) && ans<prev.size()) ans = prev.size();

            return;
        }

        // take alphabet at i-1 index
        prev.push_back(s[i-1]);
        rec(s, prev, i-1);

        // dont take alphabet
        prev.pop_back();
        rec(s, prev, i-1);
        return;
    }

    int longestPalindromeSubseq(string s) {
        string prev = "";
        int n = s.size();
        rec(s, prev, n);

        return ans;
    } */

    int longestPalindromeSubseq(string s) {
        string t = "";
        int n = s.size();

        for(int i=n-1; i>=0; i--){
            t.push_back(s[i]);
        }

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1] ==  t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }


        return dp[n][n];
    }
};