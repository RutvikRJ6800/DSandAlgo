// https://leetcode.com/problems/subsets-ii/
class Solution {
public:
    void fun(vector<int>& nums, int idx,vector<int> v,vector<vector<int>> &res){
        res.push_back(v);
        
        for(int i=idx; i<nums.size(); i++){
            if(i != idx && nums[i-1]==nums[i])continue;
            v.push_back(nums[i]);
            fun(nums,i+1,v,res);
            v.pop_back();
        }
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> v;
        fun(nums, 0, v, res);
        return res;
        
    }
};