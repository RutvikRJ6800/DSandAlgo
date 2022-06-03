// https://leetcode.com/problems/merge-sorted-array/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int k=m+n-1,i=m-1,j=n-1;
        while(k>=0){
            if(i>=0 && j>=0){
                if(nums1[i]>nums2[j]){
                    nums1[k--]=nums1[i--];
                }
                else{
                    nums1[k--]=nums2[j--];
                }
            }
            else if(i>=0){
                nums1[k--]=nums1[i--];
            }
            else
                nums1[k--]=nums2[j--];
        }
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         solution use extra space_O(N+M) time and space
//         vector<int> res;
//         int j=0,k=0;
//         for(int i=0; i<m+n; ++i){
//             if(j<m && k<n){
//                 if(nums1[j]<=nums2[k]){
//                 res.push_back(nums1[j]);
//                 j++;
//                 }
//                 else{
//                     res.push_back(nums2[k]);
//                     k++;
//                 }
//             }
//             else{
//                 if(j<m){
//                     res.push_back(nums1[j]);
//                     j++;
//                 }
//                 if(k<n){
//                     res.push_back(nums2[k]);
//                     k++;
//                 }
//             }
//         }
        
//         for(int i=0; i<m+n; ++i){
//             nums1[i]=res[i];
//         }
    }
};