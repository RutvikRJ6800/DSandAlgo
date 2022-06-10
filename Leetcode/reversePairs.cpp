// https://leetcode.com/problems/reverse-pairs/submissions/
// https://www.youtube.com/watch?v=S6rsAlj_iB4&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=20&ab_channel=takeUforward
class Solution {
public:
    
// merge sort approch - similar to count inversion problem- O(NlgN) time ans O(N) space

    int merge(vector<int>& nums, vector<int>& temp, int l,int m, int r){
        int ans=0;
        
        int i,j,k;
        i=l;
        j=m;
        
        while(i<m){
            while(j<=r && nums[i]>2*(long)nums[j]){
                j++;
            }
            ans += j-m;
            i++;
        }
        i=l;
        j=m;
        k=l;
        
        while(i<m && j<=r){
            if(nums[i]<=nums[j]){
                temp[k++]=nums[i++];
            }
            else{
                temp[k++]=nums[j++];
            }
        }
        
        while(i<m){
            temp[k++]=nums[i++];
        }
        while(j<=r){
            temp[k++]=nums[j++];
        }
        
        for(i=l; i<=r; ++i){
            nums[i]=temp[i];
        }
        return ans;
        
    }
    
    int mergeSort(vector<int>& nums,vector<int>& temp, int l,int r){
        int ans =0;
        if(l<r){
            int m = (l+r)/2;
            ans+=mergeSort(nums,temp,l,m);
            ans += mergeSort(nums,temp,m+1,r);
            ans+= merge(nums,temp,l,m+1,r);
        }
        return ans;
    }
    
    
    int reversePairs(vector<int>& nums) {
        int size=nums.size();
        vector<int> temp(size);
        return mergeSort(nums,temp,0,size-1);
    }
};