// https://leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=-1, j=0, k=nums.size()-1;

        while(j<=k){
            if(nums[j] == 0){
                swap(nums[++i], nums[j]);
                j++;
            }
            else if(nums[j] == 2){
                swap(nums[j], nums[k]);
                k--;
            }
            else{
                j++;
            }
        }
    }
};