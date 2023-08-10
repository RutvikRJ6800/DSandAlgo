// https://leetcode.com/problems/missing-number/solutions/69786/3-different-ideas-xor-sum-binary-search-java-code/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // aproach 0 O(N^2) algo: check each number present in array or not.
        // aproach 1 we can do it using sorting
        // aproach 2 use hash map to store apeared number then return non apeared number
        // aproach 3 sum;
        
        int sum = 0, n=nums.size();
        for(int i=0; i<n; i++){
            sum += nums[i];
        }

        return n*(n+1)/2 - sum;

        // aproach 4: we can also use XOR
    }
};