// https://leetcode.com/problems/jump-game/description/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxStep = 0, i = 0, n = nums.size();

        while(i < n){
            if(maxStep < i) return false;
            else{
                maxStep = max(maxStep, i + nums[i]);
            }
            i++;
        }
        return true;
    }
};