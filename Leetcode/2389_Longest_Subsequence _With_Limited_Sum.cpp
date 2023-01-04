#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /* 
    // DP Memoization approach
    int solve(vector<int> &nums, int i, int target, vector<vector<int>> &dp){
        if(i==0){ // nums finished
            if(target >= 0) return 1;
            else return 0;
        }

        if(dp[i][target] != -1) return dp[i][target];
        if(nums[i-1] <= target){
        // take not take
        dp[i][target] = max(solve(nums, i-1, target, dp), 1+solve(nums, i-1, target-nums[i-1], dp));
            return dp[i][target]; 
        }

        // note take
        dp[i][target] = solve(nums, i-1, target, dp);
        return  dp[i][target];
    }
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();

        vector<int> ans(m, 0);

        for(int i = 0; i<m; i++){
            vector<vector<int>> dp(n+1, vector<int>(queries[i]+1, -1));
            ans[i] = solve(nums, n, queries[i], dp)-1;
        }

        return ans;
    } */

    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();

        vector<int> ans(m, 0);
        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        
        sort(nums.begin(), nums.end());
        
        for(int i = 1; i<n; i++){
            prefixSum[i] += prefixSum[i-1];
        }

        for(int p = 0; p<m; p++){
            int key = queries[p];
            int i = 0;
            int j = n-1;
            int m = 0;
            while(i<j){
                m = (j + i)/2;

                if(nums[m] == key){
                    break;
                }
                else if(nums[m] < key){
                    i = m+1;
                }
                else{
                    j = m-1;
                }
            }

            if(nums[m] == key){
                ans[p] = m+1;
            }
            else{
                ans[p] = m;
            }
        }   

        return ans;
    }
};