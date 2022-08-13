#include<bits/stdc++.h>
using namespace std;

int ans=0;
void fun(vector<int>nums, int idx, int currSum, int target/*, vector<int>ds*/, vector<int>&v ){
    if(currSum == target){
        // v[0]++;
        ans++;
        return;
    }
    else{
        int i=idx;
        while(i<nums.size() && nums[i]<=target-currSum){
            fun(nums, i, currSum + nums[i], target,v);
            i++;
        }
        return;
    }
}

int combinationSum4(vector<int>& nums, int target) {
    vector<int> v(1);
    v[0]=0;
    fun(nums,0,0,target,v);
    return ans;
}

int main(){
    vector<int> nums={1,2,3};
    cout<<combinationSum4(nums,4)<<endl;
    return 0;
}



vector<int> dp(target + 1, -1);  // at start, none of the values are computed
    return helper(nums, target, dp);


int helper(vector<int>& nums, int target, vector<int>& dp){
    if(target == 0) return 1;  // base condition
    if(dp[target] != -1) return dp[target];  // if already computed for this value
    // recursive code starts -
    dp[target] = 0;
    // check for every element of nums. An element can only be taken if it is less than target.
    // If an element is chosen, recurse for remaining value.
    for(auto& num : nums) 
        if(num <= target) dp[target] += helper(nums, target - num, dp);
    return dp[target];
}