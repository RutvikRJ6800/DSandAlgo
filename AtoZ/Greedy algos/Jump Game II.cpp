// https://leetcode.com/problems/jump-game-ii/description/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), i=0, lastJumpPos = 0, jumps = 0, maxReachable = 0;

        while(i<n-1){
            maxReachable = max(maxReachable, i + nums[i]);
            if(lastJumpPos == i){
                jumps++;
                lastJumpPos = maxReachable;
            }
            i++;
        }

        return jumps;
    }
};