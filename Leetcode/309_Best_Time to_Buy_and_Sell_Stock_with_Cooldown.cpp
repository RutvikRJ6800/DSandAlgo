class Solution {
public:
    int solve(vector<int>& prices, int i, int j){
        if(i>=j) return 0;

        int buy = prices[i];

        int profit = 0;
        int maxProfit = INT_MIN;
        for(int p=i+1; p<=j; p++){
            int sell = prices[p];

            if(buy-sell > 0){
                profit = buy - sell + solve(prices, p+2, j);
            }
            else{
                buy = prices[p];
                profit = 0;
            }

            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return solve(prices, 0, n-1);
    }
};