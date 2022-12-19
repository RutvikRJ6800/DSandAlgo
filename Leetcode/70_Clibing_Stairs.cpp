class Solution {
public:
    /* RECURSIVE APPROACH
    int rec(int target, int curr){
        if(curr>target) return 0;
        if(target == curr) return 1;

        return rec(target, curr+1) + rec(target, curr+2);
    }
    int climbStairs(int n) {
        return rec(n, 0);
    }
    */

   // DP Approach
    int climbStairs(int n) {
        // return rec(n, 0);
        vector<int> dp(n+1, 0);
        if(n==1) return 1;
        if(n==2) return 2;

        dp[1]=1;
        dp[2]=2;
        for(int i=3; i<=n; i++){
            dp[i]= dp[i-1]+ dp[i-2];
        }

        return dp[n];

    }  

};