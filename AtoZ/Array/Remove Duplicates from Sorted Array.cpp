// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt=1, n=nums.size(), prev = 0;

        for(int i=1; i<n; i++){
            if(nums[prev] != nums[i]){
                nums[++prev] = nums[i];
                cnt++;
            }
        }
        return cnt;
    }
};