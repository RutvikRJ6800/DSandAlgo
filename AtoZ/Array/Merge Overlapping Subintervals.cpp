// https://leetcode.com/problems/merge-intervals/
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for(int i=1; i<intervals.size(); i++){
            // if it is overlap then merge it
            if(ans.back()[1] >= intervals[i][0]){
                ans[ans.size()-1][1] = max(ans[ans.size()-1][1], intervals[i][1]);
            }
            else{
                // else take current non overlapping interval in to ans
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};