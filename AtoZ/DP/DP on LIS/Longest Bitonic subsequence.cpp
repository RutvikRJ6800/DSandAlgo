// https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n= nums.size();
	    vector<vector<int>> dp(2, vector<int>(n,1));
	    int ans = 1;
	    for(int i=0; i<n; i++){
	        for(int j=i-1; j>=0; j--){
	            if(nums[i] > nums[j] && 1 + dp[0][j] > dp[0][i]){
	                dp[0][i] = 1 + dp[0][j];
	            }
	            
	            if(nums[i] < nums[j] && (1 + dp[0][j] > dp[1][i])){
	                dp[1][i] = 1 + dp[0][j];
	            }
	            
	            if(nums[i] < nums[j] && (1 + dp[1][j] > dp[1][i])){
	                dp[1][i] = 1 + dp[1][j];
	            }
	        }
	        
	        ans = max(max(ans, dp[0][i]), dp[1][i]);
	    }
	    
	   // for(int i=0; i<n; i++){
	   //     cout<<"0: "<<dp[0][i]<<", 1:"<<dp[1][i]<<endl;
	   // }
	    
	    
	    
	    return ans;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends