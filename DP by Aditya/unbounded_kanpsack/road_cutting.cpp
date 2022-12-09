//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    /* // reccursive approach  
    int rec(int price[], int idx, int currLength){
        if(currLength==0 || idx == 0) return 0;
        
        if(idx <= currLength){
            return max(price[idx-1]+rec(price, idx, currLength-idx), rec(price, idx-1, currLength)); 
        }
        else return rec(price, idx-1, currLength);
        
    }
    int cutRod(int price[], int n) {
        //code here
        return rec(price, n, n);
    } */
    
    
    /* Memoization Aproach
    int rec(int price[], int n, int i, vector<vector<int>> &dp){
        if(i==0 || n == 0) return 0;
        
        if(dp[n][i] != -1) return dp[n][i];
        if(n <= i){
            dp[n][i] = max(price[n-1]+rec(price, n, i-n, dp), rec(price, n-1, i, dp)); 
            return dp[n][i];
        }
        else{
            dp[n][i] = rec(price, n-1, i, dp);
            return dp[n][i];
        } 
        
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n+1, vector<int> (n+1,-1));
        return rec(price, n, n, dp);
    }
    */
   int cutRod(int price[], int n) {
        //code here
        vector<int> len(n+1);
        for(int i=0; i<n; i++)len[i]=i+1;
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<n+1; j++){
                if(len[i-1]<=j){
                    dp[i][j]=max(price[i-1]+dp[i][j-len[i-1]], dp[i-1][j]);
                }
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends