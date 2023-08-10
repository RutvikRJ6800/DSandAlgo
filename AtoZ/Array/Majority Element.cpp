// https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        // ***** O(N) time and constant space solution *****
        // see notes for other possible aproach.
        int size = nums.size();
        int ele = nums[0], freq = 1;
        for(int curr=1; curr<size; curr++){
            if(nums[curr] == ele) freq++;
            else freq--;

            if(freq<0){
                ele = nums[curr];
                freq=1;
            }
        }

        int occurance = 0;
        for(int curr=0; curr<size; curr++){
            if(ele == nums[curr]) occurance++;
        }

        if(occurance >= (size/2)) return ele;
        return -1;
    }
};