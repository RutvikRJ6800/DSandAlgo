// https://leetcode.com/problems/4sum/
#define ll long long
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            for(int m=i+1; m<n; m++){
                int j = m+1, k = n-1;
                while(j<k){
                    ll needed = target-(nums[i]+(ll)nums[m]);
                    ll currSum = nums[j] + (ll)nums[k];

                    if(currSum == needed){
                        // add current fourple
                        ans.push_back({nums[i], nums[m],nums[j], nums[k]});

                        while(j+1<n && nums[j+1] == nums[j])j++;
                        j++;

                        while(k-1>=0 && nums[k-1] == nums[k])k--;
                        k--;
                    }
                    else if(currSum > needed){
                        // decrease the curr sum
                        k--;
                    }
                    else{
                        // increase the curr sum
                        j++;
                    }
                }
                while(m+1<n && nums[m+1] == nums[m])m++;
            }
            while(i+1<n && nums[i+1] == nums[i])i++;
        }
        return ans;
    }
};