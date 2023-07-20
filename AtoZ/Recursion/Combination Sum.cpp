// https://leetcode.com/problems/combination-sum/description/
class Solution {
public:
    void rec(vector<int>& candidates, int target, int idx, int size, int sum, vector<int> &curr, vector<vector<int>> &ans){
        if(idx == size){
            if(sum == target){
                ans.push_back(curr);
            }
        }
        else if(sum > target){
            return;
        }
        else{
            // take
            sum += candidates[idx];
            curr.push_back(candidates[idx]);

            rec(candidates, target, idx, size, sum, curr, ans);

            sum -= candidates[idx];
            curr.pop_back();
            rec(candidates, target, idx+1, size, sum, curr, ans);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> ans;

        rec(candidates, target, 0, candidates.size(), 0, curr, ans);

        return ans;
    }
};