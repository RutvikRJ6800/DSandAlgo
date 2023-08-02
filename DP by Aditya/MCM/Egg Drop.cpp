// https://leetcode.com/problems/super-egg-drop/description/

class Solution {
public:
    int solve(int e, int f, vector<vector<int>> &dp){
        if(f == 0) return 0;
        else if(f == 1) return 1;
        else if(e == 1) return f;
        else if(dp[e][f] != -1) return dp[e][f];


        int ans = INT_MAX;
        // for(int k=1; k<=f; k++){
        //     int breakCase, nonBreakCase;
        //     if(dp[e-1][k-1] == -1){
        //         dp[e-1][k-1] = solve(e-1, k-1, dp);
        //     }
        //     breakCase = dp[e-1][k-1];

        //     if(dp[e][f-k] == -1){
        //         dp[e][f-k] = solve(e, f-k, dp);
        //     }
        //     nonBreakCase = dp[e][f-k];


        //     ans = min(ans, 1 + max(breakCase, nonBreakCase));
        // }

        int left = 1, right = f;
        while(left<=right){
            int k = left + (right-left)/2;
            int breakCase, nonBreakCase;
            if(dp[e-1][k-1] == -1){
                dp[e-1][k-1] = solve(e-1, k-1, dp);
            }
            breakCase = dp[e-1][k-1];

            if(dp[e][f-k] == -1){
                dp[e][f-k] = solve(e, f-k, dp);
            }
            nonBreakCase = dp[e][f-k];


            ans = min(ans, 1 + max(breakCase, nonBreakCase));

            if(breakCase < nonBreakCase){
                left = k + 1;
            }
            else{
                right = k - 1;
            }
        }

        dp[e][f] = ans;
        return dp[e][f];
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1, vector<int>(n+1, -1));

        for(int i=0; i<=k; i++){
            dp[i][0] = 0;
            dp[i][1] = 1;
        }

        for(int i=0; i<=n; i++){
            dp[1][i] = i;
        }

        return solve(k, n, dp);

        // for(int i=1; i<=n; i++){
        //     for(int j=2; j<=k; j++){
        //         int ans = INT_MAX;

        //         for(int )
        //     }
        // }
    }
};

/*
1
2
2
6
3
14
*/