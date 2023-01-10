class Solution {
public:
    /*
    RECURSION + TOP - DOWN APPROACH

    int solve(int k, vector<int> &prices, int idx, int size, bool canBuy, vector<vector<vector<int>>> &dp){
        if(idx == size) return 0;
        if(k == 0) return 0; // if no transaction avalable

        if(dp[idx][k][canBuy] != -1) return dp[idx][k][canBuy];

        if(canBuy){
            return dp[idx][k][canBuy] = max(-prices[idx] + solve(k, prices, idx+1, size, 0, dp), 0 + solve(k, prices, idx+1, size, 1, dp));
        }
        else{
            // i can sell or not sell
            return dp[idx][k][canBuy] = max(prices[idx] + solve(k-1, prices, idx+1, size, 1, dp), solve(k, prices, idx+1, size, 0, dp));
        }

    }
    int maxProfit(int k, vector<int>& prices) {
        int size = prices.size();

        vector<vector<vector<int>>> dp(size, vector<vector<int>> (k+1, vector<int>(2, -1)));
        return solve(k, prices, 0, size, 1, dp);
    }
    */

    /*
    BOTTOM - UP APPROACH

    int maxProfit(int k, vector<int>& prices) {
        int size = prices.size();

        vector<vector<vector<int>>> dp(size+1, vector<vector<int>> (k+1, vector<int>(2, 0)));
        
        for(int idx=size-1; idx>=0; idx--){
            for(int j=1; j<=k; j++){
                for(int canBuy=0; canBuy<2; canBuy++){
                    if(canBuy){
                        dp[idx][j][canBuy] = max(-prices[idx] + dp[idx+1][j][0], 0 + dp[idx+1][j][1]);
                    }
                    else{
                        // i can sell or not sell
                        dp[idx][j][canBuy] = max(prices[idx] + dp[idx+1][j-1][1], dp[idx+1][j][0]);
                    }
                }
            }
        }
        return dp[0][k][1];
    }
    */


    // SPACE OPTIMISIED APPROACH
    int maxProfit(int k, vector<int>& prices) {
        int size = prices.size();

        vector<vector<int>> curr(k+1, vector<int>(2, 0));
        vector<vector<int>> ahead(k+1, vector<int>(2, 0));
        
        for(int idx=size-1; idx>=0; idx--){
            for(int j=1; j<=k; j++){
                for(int canBuy=0; canBuy<2; canBuy++){
                    if(canBuy){
                        curr[j][canBuy] = max(-prices[idx] + ahead[j][0], 0 + ahead[j][1]);
                    }
                    else{
                        // i can sell or not sell
                        curr[j][canBuy] = max(prices[idx] + ahead[j-1][1], ahead[j][0]);
                    }
                }

                ahead = curr;
            }
        }
        return ahead[k][1];
    }
};