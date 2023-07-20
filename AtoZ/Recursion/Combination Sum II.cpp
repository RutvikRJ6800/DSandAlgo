// https://leetcode.com/problems/combination-sum-ii/description/
class Solution {
public:
    void rec(vector<int>& candidates, int target, int idx, int size, int sum, vector<int> &curr, vector<vector<int>> &ans){
        if(idx == size){
            if(sum == target){
                
                
                ans.push_back(curr);
            }
        }
        else if(target < sum){
            return;
        }
        else{
            // take
            sum += candidates[idx];
            curr.push_back(candidates[idx]);

            rec(candidates, target, idx+1, size, sum, curr, ans);

            sum -= candidates[idx];
            curr.pop_back();
            int i=idx;
            while(i<size && candidates[i] == candidates[idx]){
                i++;
            }
            rec(candidates, target, i, size, sum, curr, ans);
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        rec(candidates, target, 0, candidates.size(), 0, curr, ans);

        // vector<vector<int>> vecans;
        // for(auto it: ans){
        //     vecans.push_back(it);
        // }

        return ans;
    }
};