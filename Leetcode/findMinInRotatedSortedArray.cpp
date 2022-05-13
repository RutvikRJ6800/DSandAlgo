// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/submissions/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l,r,m,currMin;
        l=0;
        r=nums.size()-1;
        currMin=INT_MAX;
    
    // good code
        if(nums.size()==1){
            return nums[0];
        }
        
        
        while(l<r){
            m = l+(r-l)/2;
            if(m>0 && nums[m]<nums[m-1]){
                return nums[m];
            }
            else if(nums[l]<=nums[m] && nums[m]>nums[r]){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        return nums[l];




//         while(l<=r){
//             m=(l+r)/2;
//             currMin=min(currMin,nums[m]);
            
//             if(nums[l]<=nums[m]){
// //                 left part is sorted so min element may be at idx l
//                 currMin= min(currMin,nums[l]);
//                 l=m+1;
//             }
//             else{
// //                 right part is sorted so min element may be at idx m+1
//                 currMin= min(currMin,nums[m+1]);
//                 r=m-1;
//             }
//         }
//         return currMin;
    }
};