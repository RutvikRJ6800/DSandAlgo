// https://practice.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    /*void solve(set<string> &ans, vector<vector<int>> &dp, int i, int j, string curr, string &text1, string &text2){
	        if(i==0 || j == 0){
	            if(curr.size() == )
	            reverse(curr.begin(), curr.end());
	            if(ans.find(curr) == ans.end()){
	                ans.insert(curr);
	            }
	            return;
	        }
	        
	        if(text1[i-1] == text2[j-1]){
	            curr.push_back(text1[i-1]);
	            solve(ans, dp, i-1, j-1, curr, text1, text2);
	            curr.pop_back();
	        }
	        else{
	            if(dp[i][j-1] > dp[i-1][j]){
	                solve(ans, dp, i, j-1, curr, text1, text2);
	            }
	            else if(dp[i][j-1] < dp[i-1][j]){
	                solve(ans, dp, i-1, j, curr, text1, text2);
	            }
	            else{
	                solve(ans, dp, i, j-1, curr, text1, text2);
	                solve(ans, dp, i-1, j, curr, text1, text2);
	            }
	        }
	    }*/
	    
	    void solve(set<string> &ans, vector<vector<int>> &dp, int i, int j, string curr, string &text1, string &text2, int &lcsSize){
	        if(curr.size() == lcsSize){
	           // reverse(curr.begin(), curr.end());
	            if(ans.find(curr) == ans.end()){
	                ans.insert(curr);
	            }
	            return;
	        }
	        if(i>text1.size() || j>text2.size()) return;
	        
	        for(int l=i; l<=text1.size(); l++){
                for(int m=j; m<=text2.size(); m++){
                    if(text1[l-1] == text2[m-1]){
                        curr.push_back(text1[l-1]);
                        solve(ans, dp, l+1, m+1, curr, text1, text2, lcsSize);
                        curr.pop_back();
                    }
                }
            }
	        
	        
	    }
		vector<string> all_longest_common_subsequences(string text1, string text2)
		{
		    // Code here
		    int n1 = text1.size(), n2 = text2.size();

            vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
    
            for(int i=1; i<=n1; i++){
                for(int j=1; j<=n2; j++){
                    if(text1[i-1] == text2[j-1]){
                        dp[i][j] = 1 + dp[i-1][j-1];
                    }
                    else{
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }
                }
            }
    
            vector<string> uniq;
            set<string> ans;
            string curr = "";
            
            solve(ans, dp, 1, 1, curr, text1, text2, dp[n1][n2]);
            
            for(auto it: ans){
                uniq.push_back(it);
            }
            
            
            return uniq;
		}
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	vector<string> ans = ob.all_longest_common_subsequences(s, t);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}


// } Driver Code Ends