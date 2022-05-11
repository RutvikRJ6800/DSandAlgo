// Longest Palindrome in a String
// https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
  
    bool isPalindrom(string s){
    //     int i=0;
    //     int j=s.size()-1;
    //     while(i<j){
    //         if(s[i]!=s[j]){
    //             return false;
    //         }
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }  
    // string longestPalin (string S) {
    //     // code here
        
    //     string op;
    //     int maxLength=INT_MIN;
    //     int currLength=0;
    //     for(int i=0; i<S.size();i++){
    //         for(int j=i+1; j<S.size()+1; j++){
    //             currLength = j-i;
    //             if(currLength < maxLength){
    //                 continue;
    //             }
    //             bool res=isPalindrom(S.substr(i,currLength));
    //             if(res == true && currLength > maxLength){
    //                 maxLength = currLength;
    //                 op=S.substr(i,currLength);
    //             }
    //         }
    //     }
    //     return op;
        
        
        
        string longestPalin (string s) {
        
        int n = s.size();
        
        vector<vector<int> > dp(n, vector<int>(n, 0));
        
        for(int i = 0; i < n; i++)
            dp[i][i] = 1;
        
        for(int i = 0; i < n-1; i++)
            if(s[i] == s[i+1])
                dp[i][i+1] = 2;
        
        
        for(int k = 2; k < n; k++)
            for(int i = 0; i < n-k; i++)
                if(s[i] == s[i+k] and dp[i+1][i+k-1] != 0)
                    dp[i][i+k] = dp[i+1][i+k-1] + 2;
        
        
        int maxLen = 0;
        string ans = "";
        
        for(int i = 0; i < n; i++)
            for(int j = i; j < n; j++)
                if(dp[i][j] > maxLen){
                    maxLen = dp[i][j];
                    ans = s.substr(i, maxLen);
                }
        
        return ans;
          
    }
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends