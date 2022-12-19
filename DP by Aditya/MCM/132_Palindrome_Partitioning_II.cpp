// https://leetcode.com/problems/palindrome-partitioning-ii/
class Solution {
public:
    /* 
    ********************
    Reccursive Solution
    ********************
    bool isPalindrome(string s, int i, int j){
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;
    }
    int solve(string s, int i, int j){
        if(i>=j) return 0;

        if(isPalindrome(s, i, j)) return 0;

        int ans = INT_MAX;
        for(int k = i; k<j; k++){
            int tempAns = solve(s, i, k) + solve(s, k+1, j) + 1;
            ans = min(ans, tempAns);
        }

        return ans;
    }
    int minCut(string s) {
        int n = s.size();
        return solve(s, 0, n-1);
    } */

     /* 
     *********************
     MEMOIZATION APPROACH
     *********************

     bool isPalindrome(string s, int i, int j){
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;
    }
    int solve(string s, int i, int j, vector<vector<int>> &dp){
        if(i>=j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(isPalindrome(s, i, j)) return 0;

        int ans = INT_MAX;
        for(int k = i; k<j; k++){
            int tempAns = solve(s, i, k, dp) + solve(s, k+1, j, dp) + 1;
            ans = min(ans, tempAns);
        }

        dp[i][j] = ans;
        return dp[i][j];
    }
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(s, 0, n-1, dp);
    } */

    /*
    ******************
    STRIVER RECCURSION
    ******************
    
    bool isPalindrome(string s){
        int i = 0;
        int j = s.size()-1;
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;
    }
    int striver(string s, int start){
        int n = s.size();
        if(start == n) return 0; // whole string must be palindrome

        string temp = "";
        int ans = INT_MAX;
        for(int i = start; i<=n; i++){
            temp.push_back(s[i]);

            if(isPalindrome(temp)){
                // since left part is palindrome we can partition here.
                int tempAns = 1 + striver(s, i+1);
                ans = min(ans, tempAns);
            }

        }
        return ans;
    }

    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        return striver(s, 0);
    }
    */
};