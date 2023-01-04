class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curr = 0, maxTarget = nums[0], n = nums.size();

        if(n==1) return true;

        while(curr<n && curr<=maxTarget){
            if(maxTarget >= n-1){
                return true;
            }

            maxTarget = max(maxTarget, curr + nums[curr]);
            curr++;
        }

        return false;
    }
};