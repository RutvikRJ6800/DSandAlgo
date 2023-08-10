// https://www.codingninjas.com/studio/problems/matrix-chain-multiplication_624880?leftPanelTab=0

#include <bits/stdc++.h>
int solve(int *arr, int i, int j, vector<vector<int>> &dp){

    if(i>=j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = 1e6;

    for(int k=i; k<j; k++){

        int curr = solve(arr, i, k, dp) + solve(arr, k+1, j, dp) + arr[i-1]*arr[k]*arr[j];
        ans = min(ans, curr);
    }

    return dp[i][j] = ans;
}
int matrixChainMultiplication(int* arr, int n) {
    // Write your code here
    /*
    MEMOIZATION
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return solve(arr, 1, n, dp);
    */

    vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
    for(int i=n-1; i>=1; i--){
        for(int j=i+1; j<=n; j++){
            int ans = 1e6;
            for(int k=i; k<j; k++){
                int curr = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                ans = min(ans, curr);
            }
            dp[i][j] = ans;
        }
    }
    return dp[1][n];
}