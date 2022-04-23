class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i,j;
        j=0;
        for(i=1; i<nums.size();i++){
            if(nums[i]!=nums[j]){
                j++;
                nums[j] = nums[i];
            }
        }
    
        return ++j;
    }
};