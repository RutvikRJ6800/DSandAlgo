// https://leetcode.com/problems/maximum-number-of-groups-with-increasing-length/description/

class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        sort(usageLimits.begin(), usageLimits.end());
        int n = usageLimits.size();
        
        
        int ans = 0; // ans denotes number of group we created group
        long long sum = 0; // total number of element
        for(int i=0; i<n; i++){
            sum += usageLimits[i];
            if(sum >= (ans+1LL)*(ans+2)/2){ // if from the sum of ele
                                            // we can create ans + 1 length group then increase ans
                ans++;
            }
        }
        
        return ans; // return ans
    }
};

/*
[1,2,5]
[4,5,6]
[2,2,2] --> 3
[2,2,4]
*/