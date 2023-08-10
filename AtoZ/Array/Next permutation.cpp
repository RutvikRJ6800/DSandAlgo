// https://leetcode.com/problems/next-permutation/description/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int b,idx;
        b=n-2;
        while(b>=0 && nums[b]>=nums[b+1])b--;
        
        
        
        if(b<0){
            reverse(nums.begin(),nums.end());
        }
        else{
            idx=n-1;
            while(nums[idx]<=nums[b])idx--;
            swap(nums[b],nums[idx]);
            reverse(nums.begin()+1+b,nums.end());
        }
        
    }
};