// https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    int i=0, j=0, patLen = pat.size(), n = txt.size(), cnt = 0, ans = 0;
	    int txtFreq[26] = {0};
	    
	    for(int i=0; i<patLen; i++){
	        if(txtFreq[pat[i]-'a'] == 0) cnt++;
	        txtFreq[pat[i]-'a']++;
	    }
	    
	    while(j<n){
	        if(txtFreq[txt[j] - 'a'] == 1){
	            cnt--;
	        }
	        txtFreq[txt[j]-'a']--;
	        
	        if(j-i+1 < patLen){
	            j++;
	        }
	        
	        else if(j - i + 1  == patLen){
	           // cout<<j<<endl;
	            
	            if(cnt==0) ans++;
	            
	            // move window
	            if(txtFreq[txt[i]-'a'] == 0) cnt++;
	            txtFreq[txt[i]-'a']++;
	            i++;
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
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends