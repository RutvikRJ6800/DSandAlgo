// https://leetcode.com/problems/longest-consecutive-sequence/submissions/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_map<int, bool> mp;
        for(auto num:nums){
            mp[num] = 1;
        }

        int maxLength = 0;
        for(int num: nums){
            int length = 0;
            if(mp[num-1] == 1) continue;

            while(mp[num]){
                length++;
                num = num+1;
            }
            maxLength = max(maxLength, length);
        }
        return maxLength;
    }
};