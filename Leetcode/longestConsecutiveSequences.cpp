// https://leetcode.com/problems/longest-consecutive-sequence/
// https://www.youtube.com/watch?v=qgizvmgeyUM&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=22
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    // approch-1 use hashset and find length of consecutive eles
        // time-O(N) and space-O(1);
        if(nums.size()==0){
            return 0;
        }
        int max=INT_MIN;
        unordered_set<int> s;
        for(int i=0; i<nums.size(); ++i){
            s.insert(nums[i]);
        }
        
        for(int i=0; i<nums.size(); ++i){
            int curr = nums[i];
            if(s.find(curr-1)!=s.end()){
                continue;
            }
            else{
                int cnt=0;
                while(s.find(curr++)!=s.end())cnt++;
                if(cnt>max)max=cnt;
            }
        }
        return max;

        // approach-2 sort array and find length of consecutive eles
        // time-O(NlgN), space-O(N)if sorting algo is outplace else O(1);
        
    }
};