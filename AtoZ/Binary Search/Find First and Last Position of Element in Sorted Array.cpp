// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/


class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
    int a=-1;
    int b=-1, n = arr.size();
    
    int s=0;
    int e=n-1;

    while(s<=e){
        int mid=s+(e-s)/2;

        if(arr[mid]<target){
            s=mid+1;
        }else{
            a=mid;
            e=mid-1;
        }
    }

    if(a >= 0 && a<n && arr[a] != target) a = -1;
    
    s=0;
    e=n-1;
    
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid] > target){
            e=mid-1;
        }else{
            s=mid+1;
            b=mid;
        }
    }

    if(b >= 0 && b<n && arr[b] != target) b = -1;

    return {a,b};
    }
};