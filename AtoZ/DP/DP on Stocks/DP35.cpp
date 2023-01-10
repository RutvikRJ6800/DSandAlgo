 // https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int size = prices.size();
        int maxProfit = INT_MIN;

        for(int i=1; i<size; i++){
            int sell = prices[i];
            int profit = sell - buy;

            maxProfit = max(maxProfit, profit);
            if(profit<0){
                buy = prices[i];
            }
        }

        return maxProfit>0?maxProfit:0;
    }
};