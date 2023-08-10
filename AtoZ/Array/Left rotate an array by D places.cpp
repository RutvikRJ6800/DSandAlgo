// https://leetcode.com/problems/rotate-array/description/
// Question is slightly change here we will shift array right \
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k = k%n;
        vector<int> temp;
        for(int i=n-k; i<n; i++){
            temp.push_back(nums[i]);
        }

        for(int i=n-1; i>=k; i--){
            nums[i] = nums[i-k];
        }


        for(int i=0; i<k; i++){
            nums[i] = temp[i];
        }

    }
};