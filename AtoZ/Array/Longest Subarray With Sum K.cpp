// https://www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_6682399?leftPanelTab=0

#include <bits/stdc++.h>
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    long long i=0, j=0, n = a.size(), sum = 0, ans = 0;
    while(j<n){
        sum += a[j];
        if(sum < k){
            j++;
        }
        else if(sum >= k){
            
            while(sum > k && i<=j){
                sum -= a[i];
                i++;
            }

            if(sum == k){
                ans = max(ans, j-i+1);
            }
            j++;
        }
    }
    return ans;
}