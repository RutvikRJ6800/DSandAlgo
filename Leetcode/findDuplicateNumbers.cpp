// https://leetcode.com/problems/find-the-duplicate-number/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
//         use set-O(N)time and space
        // set<int> s;
        // for(int i=0; i<nums.size();++i){
        //     if(!s.empty() && s.find(nums[i])!=s.end()){
        //         return nums[i];
        //     }
        //     else{
        //         s.insert(nums[i]);
        //     }
        // }
        // return -1;
//         use sorting _O(NlgN) time constant space
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); ++i){
            if(nums[i-1]==nums[i]){
                return nums[i];
            }
        }
        return -1;
        
    }
};