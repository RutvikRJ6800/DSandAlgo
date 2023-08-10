// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

class Solution {
public:
    int solve(vector<int>& cuts, int ci, int cj, vector<vector<int>> &dp){
        if(ci > cj) return 0;
        if(dp[ci][cj] != -1) return dp[ci][cj];
        // cout<<ci<<","<<cj<<endl;

        int ans = 1e8;
        for(int k=ci; k<=cj; k++){
            int curr = (cuts[cj+1] - cuts[ci-1]) + solve(cuts, ci, k-1, dp) + solve(cuts, k+1, cj, dp);

            ans = min(ans, curr);
        }

        return dp[ci][cj] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        /*
        sort(cuts.begin(), cuts.end());
        int ncuts = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.insert(cuts.end(), n);
        vector<vector<int>> dp(ncuts+1, vector<int>(ncuts+1, -1));
        return solve(cuts, 1, ncuts, dp);
        */

        int ncuts = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.insert(cuts.end(), n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(ncuts+2, vector<int>(ncuts+2, 0));

        for(int i=ncuts; i>=1; i--){
            for(int j=i; j<=ncuts; j++){
                // if(i>j) continue;
                int ans = 1e8;
                cout<<i<<","<<j<<endl;
                for(int k=i; k<=j; k++){
                    int curr = (cuts[j+1] - cuts[i-1]) + dp[i][k-1] + dp[k+1][j];
                    ans = min(ans, curr);
                }
                dp[i][j] = ans;
            }
        }

        return dp[1][ncuts];   
    }
};

/*

*/