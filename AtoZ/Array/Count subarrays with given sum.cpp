// https://leetcode.com/problems/subarray-sum-equals-k/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int preSum = 0;
        int occurance = 0;
        mp[0] = 1;
        for(int num: nums){
            preSum += num;
            int needed = preSum - k;
            occurance += mp[needed];

            mp[preSum]++;
        }
        return occurance;
    }
};