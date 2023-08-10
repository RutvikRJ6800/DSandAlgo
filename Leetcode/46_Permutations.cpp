// https://leetcode.com/problems/permutations/description/

class Solution {
public:
    void solve(vector<int>& nums, vector<bool>& taken, vector<vector<int>> &ans, vector<int> &ds){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(taken[i] == 0){
                taken[i] = 1;
                ds.push_back(nums[i]);
                solve(nums, taken, ans, ds);

                taken[i] = 0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // TC: O(n⋅n!) and SC: O(n);
        int n = nums.size();
        vector<bool> taken(n, 0);
        vector<vector<int>> ans;
        vector<int> ds;
        solve(nums, taken, ans, ds);
        return ans;
    }
};