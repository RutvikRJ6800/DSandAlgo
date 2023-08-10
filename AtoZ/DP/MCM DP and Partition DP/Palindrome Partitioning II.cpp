// https://leetcode.com/problems/palindrome-partitioning-ii/description/
class Solution {
public:
    bool isPalindrome(string &s, int i, int j){
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    /*
    MEMOIZATION O(N^3) time and O(N^2) space
    int solve(string &s, int i, int j, vector<vector<int>> &dp){
        if(i==j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(isPalindrome(s, i, j)) return 0;


        int ans = INT_MAX;
        for(int k=i; k<j; k++){
            if(isPalindrome(s, i, k)){
                ans = min(ans, 1 + solve(s, k+1, j, dp));
            }
        }

        return dp[i][j] = ans;
    }
    */


    /*
    MEMOIZATION O(N^2) time and O(N) space
    int solveInN2Time(string &s, int start, int &n, vector<int>& dp){
        if(start == n) return -1;
        if(dp[start] != -1) return dp[start];

        int ans = INT_MAX;
        for(int i=start; i<n; i++){
            if(isPalindrome(s, start, i)){
                ans = min(ans, 1 + solveInN2Time(s, i+1, n, dp));
            }
        }
        return dp[start] = ans;

    }
    */
    int minCut(string &s) {

        /*
        MEMOIZATION O(N^3) time and O(N^2) space
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(s, 0, n-1, dp);
        */


        /*
    MEMOIZATION O(N^2) time and O(N) space
        int n = s.size();
        vector<int> dp(n, -1);
        return solveInN2Time(s, 0, n, dp);
        */

        // Tabulation Code
        int n = s.size();
        vector<int> dp(n+1, -1);
        for(int start=n-1; start>=0; start--){
            int ans = INT_MAX;
            for(int i=start; i<n; i++){
                if(isPalindrome(s, start, i)){
                    ans = min(ans, 1 + dp[i+1]);
                }
            }
            dp[start] = ans;
        }
        return dp[0];
    }
};
