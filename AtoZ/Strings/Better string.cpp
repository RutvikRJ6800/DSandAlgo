// https://practice.geeksforgeeks.org/problems/better-string/1
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void rec(string &s, int idx, unordered_set<string> &st, string &curr){
        if(idx == -1){
            if (st.find(curr) == st.end())
            st.insert(curr);
        }
        else{
            // take
            curr.push_back(s[idx]);
            rec(s, idx-1, st, curr);
            curr.pop_back();
            
            // non take
            rec(s, idx-1, st, curr);
        }
    }
    string betterString(string str1, string str2) {
        // code here
        
        // reccursive solution
        // unordered_set<string> s1;
        // unordered_set<string> s2;
        // string curr = "";
        
        // rec(str1, str1.size() - 1, s1, curr);
        
        // curr = "";
        // rec(str2, str2.size() - 1, s2, curr);
        
        // if(s1.size() >= s2.size()) return str1;
        // else return str2;
        
        // dynamic progg
        
        int lastOcc[26];
        int n1 = str1.size(), n2 = str2.size();
        int dp1[n1+1] = {0};
        int dp2[n2+1] = {0};
        
        dp1[0] = 1;
        dp2[0] = 1;
        
        memset(lastOcc, -1, sizeof(lastOcc));
        
        for(int i=0; i<n1; i++){
            dp1[i+1] = dp1[i]*2 - (lastOcc[str1[i] - 'a'] == -1? 0 : dp1[lastOcc[str1[i] - 'a'] - 1]);
            lastOcc[str1[i]-'a'] = i+1;
            // cout<<dp1[i+1]<<":";
        }
        
        // cout<<endl;
        
        memset(lastOcc, -1, sizeof(lastOcc));
        
        for(int i=0; i<n2; i++){
            dp2[i+1] = dp2[i]*2 - (lastOcc[str2[i] - 'a'] == -1? 0 : dp2[lastOcc[str2[i] - 'a'] - 1]);
            lastOcc[str2[i]-'a'] = i+1;
            // cout<<dp2[i+1]<<":";
        }
        
        // cout<<endl;
        
        // cout<<dp1[n1]<<", "<<dp2[n2];
        
        return dp1[n1] >= dp2[n2] ? str1:str2;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends