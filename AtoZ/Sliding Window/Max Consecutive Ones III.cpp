// https://leetcode.com/problems/max-consecutive-ones-iii/


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int freq[2] = {0}, i=0, j=0, n = nums.size(), ans = 0;

        while(j<n){
            freq[nums[j]]++;
            if(freq[0] < k){
                ans = max(ans, freq[0] + freq[1]);
                j++;
            } 
            else if(freq[0] == k){
                ans = max(ans, freq[0] + freq[1]);
                j++;
            }
            else if(freq[0] > k){
                while(freq[0] > k){
                    freq[nums[i]]--;
                    i++;
                }
                if(freq[0] == k){
                    ans = max(ans, freq[0] + freq[1]);
                }
                j++;
            }
        }

        return ans;
    }
};
