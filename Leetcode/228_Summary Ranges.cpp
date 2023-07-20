// https://leetcode.com/problems/summary-ranges/description/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        int prev = -1;
        vector<string> ans;

        if(n==0) return ans;

        for(int i=0; i<n; ++i){
            if(prev == -1){
                prev = i;
            }
            else if(nums[i-1] + 1 != nums[i]){
                if(i-1 == prev){
                    // only one ele in range
                    ans.push_back(to_string(nums[prev]));
                    prev = i;
                }
                else{
                    // two ele in range
                    ans.push_back(to_string(nums[prev]) + "->" + to_string(nums[i-1]));
                    prev = i;
                }
            }
        }

        if(n-1 == prev){
            // only one ele in range
            ans.push_back(to_string(nums[prev]));
        }
        else{
            // two ele in range
            ans.push_back(to_string(nums[prev]) + "->" + to_string(nums[n-1]));
        }

        return ans;
    }
};