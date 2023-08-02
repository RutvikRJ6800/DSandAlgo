// https://leetcode.com/problems/largest-divisible-subset/

class Solution {
public:
    void solve(vector<int>& nums, int idx, vector<int>& curr,vector<int>& ans){
        if(idx == nums.size()){
            if(ans.size()<curr.size()){
                ans = curr;
            }
            return ;
        }

        // take
        if(curr.size()>1){
            int prev = curr[curr.size()-1];
            if(prev % nums[idx] == 0 || nums[idx] % prev == 0){
                curr.push_back(nums[idx]);
                solve(nums, idx+1, curr, ans);
                curr.pop_back();
            }
        }
        else{
            curr.push_back(nums[idx]);
            solve(nums, idx+1, curr, ans);
            curr.pop_back();
        }
        // not take
        solve(nums, idx+1,curr, ans);

    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), hash1(n,0);

        vector<int> ans;
        sort(nums.begin(), nums.end());

        int lis = 0, prevIdx=0;
        for(int i=0; i<n; i++){
            // int prev = 0;
            hash1[i] = i;
            for(int j=i-1; j>=0; j--){
                if(((nums[i] % nums[j] == 0) || (nums[j] % nums[i] == 0)) && dp[j] + 1 > dp[i]){
                    hash1[i] = j; 
                    dp[i] = 1 + dp[j];
                }
            }

            if(lis<dp[i]){
                lis = dp[i];
                prevIdx = i;
            }
        }

        while(hash1[prevIdx] != prevIdx){
            ans.push_back(nums[prevIdx]);
            prevIdx = hash1[prevIdx];
        }
        ans.push_back(nums[prevIdx]);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};