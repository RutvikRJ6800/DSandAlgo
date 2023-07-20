// https://leetcode.com/problems/subarrays-with-k-different-integers/description/

class Solution {
public:
    int atmost(vector<int>& nums, int k){
        int n = nums.size(), ans = 0, i=0, j=0;
        unordered_map<int, int> freq;

        while(j<n){
            freq[nums[j]]++;

            if(freq.size() <= k){
                ans += (j-i + 1);
                j++;
            }
            else if(freq.size() > k){
                while(freq.size() > k){
                    if(freq[nums[i]] == 1){
                        freq.erase(nums[i]);
                    }
                    else{
                        freq[nums[i]]--;
                    }

                    i++;
                }

                if(freq.size() <= k){
                    ans += (j-i + 1);
                }
                j++;
            }
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k-1);
    }
};