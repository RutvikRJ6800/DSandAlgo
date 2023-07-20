// https://leetcode.com/problems/subsets-ii/description/
class Solution {
public:
void rec(vector<int>& candidates, int idx, int size, vector<int> &curr, vector<vector<int>> &ans){
        if(idx == size){    
            ans.push_back(curr);
        }
        else{
            // take
            curr.push_back(candidates[idx]);

            rec(candidates, idx+1, size, curr, ans);
            curr.pop_back();

            int i=idx;
            while(i<size && candidates[i] == candidates[idx]){
                i++;
            }

            rec(candidates, i, size, curr, ans);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        rec(nums, 0, nums.size(), curr, ans);

        // vector<vector<int>> vecans;
        // for(auto it: ans){
        //     vecans.push_back(it);
        // }

        return ans;    
    }
};