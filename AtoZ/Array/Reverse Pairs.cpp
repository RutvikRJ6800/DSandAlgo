// https://leetcode.com/problems/reverse-pairs/

class Solution {
public:
    int merge(vector<int>& arr,int start,int mid,int end){
        // cout<<start<<","<<end<<endl;
        int i=start, j=mid, k=0;
        int ans = 0;

        while(i<mid){
            while(j<=end && arr[i]>2*(long long)arr[j]){
                j++;
            }
            ans += (j-mid);
            i++;
        }


        vector<int> temp(end-start+1);
        i=start, j=mid, k=0;
        while(i<mid && j<=end){
            if(arr[i] <= arr[j]){
                temp[k++] = arr[i++];
            }
            else{
                temp[k++] = arr[j++];
            }
        }
        while(i<mid){
            temp[k++] = arr[i++];
        }
        while(j<=end){
            temp[k++] = arr[j++];
        }
        
        i=start, k=0;
        while(i<=end){
            arr[i++] = temp[k++];
        }
        return ans;
    }
    int mergeSort(vector<int>& arr,int start,int end){
        int ans = 0;
        // cout<<start<<","<<end<<endl;
        if(start<end){
            int mid = start + (end-start)/2;
            ans += mergeSort(arr, start, mid);
            ans += mergeSort(arr, mid+1, end);
            ans += merge(arr, start, mid+1, end);
        }
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};