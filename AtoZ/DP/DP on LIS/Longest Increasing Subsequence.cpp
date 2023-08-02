// https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /*
        O(N2) time and space complexity
        int n = nums.size(), ans = 1;
        vector<int> dp(n, 1);
        for(int i=1; i<n; i++){
            int maxi = 0;
            for(int j=i-1; j>=0; j--){
                if(nums[j] < nums[i]){
                    maxi = max(maxi, dp[j]);
                }
            }
            dp[i] += maxi;
            ans = max(ans, dp[i]);
        }
        return ans;
        */

        /*
        O(NlogN) time and O(N) space complexity
        */

        vector<int> seq;
        int n = nums.size();
        for(int i=0; i<n; i++){
            auto it = lower_bound(seq.begin(), seq.end(), nums[i]);

            if(it == seq.end()){
                seq.push_back(nums[i]);
            }
            else{
                *it = nums[i];
            }

        }

        return seq.size();

    }
};