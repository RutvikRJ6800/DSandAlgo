/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=INT_MIN;
        int currProfit;
        int buyingPrice = prices[0];
        if(prices.size()<=1){
            return 0;
        }
        for(int i=1; i<prices.size(); i++){
            currProfit=prices[i]-buyingPrice;
            if(currProfit<=0){
                buyingPrice=prices[i];
                currProfit=0;
            }
            if(currProfit>maxProfit){
                maxProfit=currProfit;
            }
        }
        return maxProfit;
    }
};