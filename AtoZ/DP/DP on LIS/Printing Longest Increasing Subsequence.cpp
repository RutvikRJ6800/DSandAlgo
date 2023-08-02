// https://www.codingninjas.com/studio/problems/printing-longest-increasing-subsequence_8360670

vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
	// Write your code here
	vector<int> dp(n);
	int lis = 0;

	for(int i=0; i<n; i++){
		int ans = 0;
		for(int j=i-1; j>=0; j--){
			if(arr[i]>arr[j]){
				ans = max(ans , dp[j]);
			}
		}
		dp[i] = ans + 1;
		lis = max(lis, dp[i]);
	}

	vector<int> ans;
	for(int i=n-1; i>=0; i--){
		if(dp[i] == lis){
			ans.push_back(arr[i]);
			lis--;
		}
	}

	reverse(ans.begin(), ans.end());
	return ans;
}
