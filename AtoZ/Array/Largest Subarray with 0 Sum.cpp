// https://www.codingninjas.com/studio/problems/longest-subarray-with-zero-sum_6783450

#include<vector>
#include<bits/stdc++.h>

int getLongestZeroSumSubarrayLength(vector<int> &arr){
	// Write your code here.
	unordered_map<int, int> mp;
	int sum = 0, ans = 0;
	for(int i=0; i<arr.size(); i++){
		sum += arr[i];
		if(sum == 0) ans = max(ans, i+1);

		if(mp.find(sum) != mp.end()){
			ans = max(ans, i-mp[sum]);
		}
		else{
			mp[sum] = i;
		}
	}
	return ans;
}