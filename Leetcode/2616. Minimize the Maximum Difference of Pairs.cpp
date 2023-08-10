// https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/

class Solution {
public:
    bool possible(vector<int>& nums, int mid, int n, int p){
        int cnt = 0,i=1;
        while(i<n){
            if(nums[i]-nums[i-1] <= mid){
                cnt++;
                i+=2;
            }
            else i++;

            if(cnt>=p) return true;
        }

        if(cnt>=p) return true;
        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int left = 0, right = INT_MIN, n = nums.size();
        for(int i=1; i<n; i++){
            // left = min(left, nums[i]-nums[i-1]);
            right = max(right, nums[i]-nums[i-1]);
        }

        if(n==1) return 0;
        int ans;
        while(left<=right){
            int mid = left + (right-left)/2;

            if(possible(nums, mid, n, p)){
                ans = mid;
                right = mid-1;

            }
            else{
                left = mid + 1;
            }
        }
        
        return ans;
    }
};