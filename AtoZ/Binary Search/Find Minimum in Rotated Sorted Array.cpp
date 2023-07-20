// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

class Solution {
public:
    int findMin(vector<int>& arr) {
        int s=0;
        int e=arr.size()-1, mini = INT_MAX;

        while(s<=e){
            int mid=s+(e-s)/2;

            // cout<<s<<","<<e<<","<<mid<<endl;
            if(arr[s] <= arr[mid]){
                // left part is sorted
                mini = min(mini, arr[s]);
                s = mid + 1;

            }else{
                // right part is sorted
                mini = min(mini, arr[mid]);
                e = mid - 1;
            }
        }

        return mini;
    }
};