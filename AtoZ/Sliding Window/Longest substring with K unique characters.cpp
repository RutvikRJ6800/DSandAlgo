// https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        int freq[26] = {0};
        int cnt = 0, i=0, j=0, ans = -1, n=s.size();
        
        while(j<n){
            if(freq[s[j]-'a'] == 0) cnt++;
            freq[s[j]-'a']++;
            
            
            // cout<<j<<","<<cnt<<endl;
            
            if(cnt<k) j++;
            else if(cnt == k){
                ans = max(ans, j - i + 1);
                j++;
            }
            else if(cnt > k){
                while(cnt > k){
                    if(freq[s[i]-'a'] == 1){
                        cnt--;
                    }
                    freq[s[i]-'a']--;
                    i++;
                }
                if(cnt == k){
                    ans = max(ans, j - i + 1);
                }
                j++;
            }
            
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends