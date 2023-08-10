// https://leetcode.com/problems/two-sum/description/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // sort(nums.begin(), nums.end());
        int n = nums.size();

        // while(i<j){
        //     int sum = nums[i] + nums[j];
        //     if(sum == target) return {i, j};
        //     else if(sum < target) i++;
        //     else j--;
        // }
        // return {-1,-1};

        unordered_map<int, int> m;
        for(int i=0; i<n; i++){
            int need = target-nums[i];
            if(m.find(need) != m.end()) return {i, m[need]};
            m[nums[i]] = i;
            
        }

        return {-1, -1};
    }
};