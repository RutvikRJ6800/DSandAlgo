// https://leetcode.com/problems/sort-colors/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // for(int i=0; i<nums.size();i++){
        //     for(int j=i; j<nums.size(); j++){
        //         if(nums[i]>nums[j]){
        //             swap(nums[i],nums[j]);
        //         }
        //     }
        // }
        
        
//         counting sort approch - O(N) time; O(3) space;
        vector<int> count(3,0);
        for(int i=0; i<nums.size(); i++){
            count[nums[i]]++;
        }
        int j=0,i=0;
        
       while(i<nums.size()){
            if(count[j]==0){
                j++;
                continue;
            }
            nums[i]=j;
            count[j]--;
           i++;
        }
        
    }
};