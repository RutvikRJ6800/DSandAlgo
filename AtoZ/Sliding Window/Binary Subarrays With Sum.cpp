// https://leetcode.com/problems/binary-subarrays-with-sum/description/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(), i = 0, j=0, sum = 0, cnt = 0, ans = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        
        for(auto num: nums){
            sum += num;

            int requiedsum = sum - goal;

            if(mp.find(requiedsum) != mp.end()){
                ans += mp[requiedsum];
            }

            mp[sum]++;
        }
        return ans;
    }
};