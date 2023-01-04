class Solution {
public:
    
    // MEMOIZATION APPROACH

    int solve(vector<int> &cuts, int i, int j, vector<vector<int>> &dp){
        if(i>j) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        for(int c=i; c<=j; c++){
            int cost = cuts[j+1] - cuts[i-1] + solve(cuts, i, c-1, dp) + solve(cuts, c+1, j, dp);
            ans = min(ans, cost);
        }
        return dp[i][j] = ans;
    }
    
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        int csize = cuts.size();

        vector<vector<int>> dp(csize+1, vector<int>(csize, -1));
        return solve(cuts, 1 , cuts.size()-2, dp);
    }

    // NOT WORKING BOTTOM UP CODE
    // int minCost(int n, vector<int>& cuts) {
    //     int csize = cuts.size();
    //     cuts.push_back(n);
    //     cuts.insert(cuts.begin(), 0);
    //     sort(cuts.begin(), cuts.end());

    //     vector<vector<int>> dp(csize+3, vector<int>(csize+3, 0));

    //     for(int i=csize; i>=1; i--){
    //         for(int j=1; j>=csize; j++){
    //             if(i>j) continue;
    //             int ans = INT_MAX;
    //             for(int c=i; c<=j; c++){
    //                 int cost = cuts[j+1] - cuts[i-1] + dp[i][c-1] + dp[c+1][j];
    //                 ans = min(ans, cost);
    //             }
    //             dp[i][j] = ans;
    //         }
    //     }
    //     return dp[1][csize];
    // }
};