// https://leetcode.com/problems/subsets/description/
class Solution {
public:
    void rec(vector<int>& nums, int idx, vector<vector<int>> &ans, vector<int> & curr){
        if(idx == -1){
            ans.push_back(curr);
        }
        else{
            // take
            curr.push_back(nums[idx]);
            rec(nums, idx -1, ans, curr);

            curr.pop_back();
            // non take
            rec(nums, idx-1, ans, curr);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;

        rec(nums, nums.size()-1, ans, curr);

        return ans;
    }
};