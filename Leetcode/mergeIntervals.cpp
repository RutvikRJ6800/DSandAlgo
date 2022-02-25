// https://leetcode.com/problems/merge-intervals/submissions/
class Solution {
public:
    
    static bool cmp(vector<int> &a, vector<int> &b){
        
        if(a[0]==b[0]) return a[1]<b[1];
        else
            return a[0]<b[0];
        
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
//         sort based on startdate to 2 consicutive element
        
        sort(intervals.begin(),intervals.end(),cmp);
        
        size_t i=0;
        size_t size=intervals.size();
        for(size_t j=1; j<size; j++){
            
            if(intervals[i][1]>=intervals[j][0]){
                
                intervals[i][0] =min(intervals[i][0],intervals[j][0]);
                intervals[i][1] =max(intervals[i][1],intervals[j][1]);
                
            }
            else{
                i++;
                intervals[i]=intervals[j];
            }
                
            
            
            
            
            
        }
        intervals.resize(i+1);
        return intervals;
    }
};