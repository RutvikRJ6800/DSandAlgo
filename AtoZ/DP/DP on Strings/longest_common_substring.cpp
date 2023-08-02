//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
/*  // RECURSIVE APPROACH   
    int ans = 0;
    
    void rec(string S1, string S2, int n, int m, int currLength){
        if(n==0 || m==0) return;
        
        if(S1[n-1] == S2[m-1]){
            // cout<<"n: "<<n<<",m:"<<m<<endl;
            if(ans<currLength + 1) ans = currLength + 1; 
            
            rec(S1, S2, n-1, m-1, currLength+1);
            return ;
        } 
        
        currLength = 0;
        rec(S1, S2, n, m-1, currLength);
        rec(S1, S2, n-1, m, currLength);
        return;
    }
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        rec(S1, S2, n, m, 0);
        return ans;
    } */

    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        // rec(S1, S2, n, m, dp);
        int ans = 0;
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(S1[i-1] == S2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    // if(ans < dp[n][m]) ans = dp[n][m];
                    // cout<<i<<","<<j<<endl;
                    ans = max(ans, dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends

/*

17 60
KXCGMTMVVGFQQWSPD
JXZADDUKVLQPKUZJZHWSUTPCAFSYAIBJHAMMEGWBTPQELRNKBLDXGUZGCSEC*/