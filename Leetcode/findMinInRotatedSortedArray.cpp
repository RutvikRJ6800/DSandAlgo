// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/submissions/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l,r,m,currMin;
        l=0;
        r=nums.size()-1;
        currMin=INT_MAX;
        
        while(l<=r){
            m=(l+r)/2;
            currMin=min(currMin,nums[m]);
            
            if(nums[l]<=nums[m]){
//                 left part is sorted so min element may be at idx l
                currMin= min(currMin,nums[l]);
                l=m+1;
            }
            else{
//                 right part is sorted so min element may be at idx m+1
                currMin= min(currMin,nums[m+1]);
                r=m-1;
            }
        }
        return currMin;
    }
};