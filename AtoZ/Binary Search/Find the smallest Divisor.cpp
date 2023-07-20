// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/

class Solution {
public:
    int findDivisor(vector<int>& nums, int threasold, int mid) {
        int sum = 0;
        for(auto it: nums){
            int q = ceil((double)it / mid);
            // cout<<q<<", ";
            sum += q;
        }
        // cout<<": "<<sum<<endl;
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = INT_MIN, n = nums.size(), ans = -1;

        for(int i=0; i<n; ++i){
            right = max(right, nums[i]);
        }


        while(left <= right){
            int mid = left + (right - left)/2;
            // cout<<left<<", "<<right<<", "<<mid<<endl;
            if(findDivisor(nums, threshold, mid) <= threshold){
                right = mid - 1;
                ans = mid;
            }
            else{
            left = mid + 1;
            }
        }

        return ans;
    }
};