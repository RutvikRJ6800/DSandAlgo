// https://practice.geeksforgeeks.org/problems/count-number-of-substrings4528/1
//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long int countStringLessEqualK(string s, int k){
        long long int cnt=0;
        int distinct = 0, left = 0;
        int freq[26] = {0};

        for(int i=0; i<s.size(); i++){
            if(freq[s[i] - 'a'] == 0){
                distinct++;
            }
            freq[s[i]-'a']++;
            
            while(distinct > k){
                freq[s[left]-'a']--;
                
                if(freq[s[left]-'a'] == 0){
                    distinct--;
                }
                
                left++;
            }
            
            cnt += (i - left + 1);
        }
        
        return cnt;
    }
    long long int substrCount (string s, int k) {
    	//code here.
        // return countStringLessEqualK(s, k) - countStringLessEqualK(s, k-1);
        
        unordered_map<char, int> big, small;
        
        int i=0, n = s.size(), left = 0;
        long long int cnt = 0;
        
        
        while(i<n){
            // check if big or small less than expected size
            cout<<i<<",";
            if(small.size() < k-1 || big.size() < k){
                if(small.size() < k-1){
                    small[s[i]-'a']++;
                }
                if(big.size() < k){
                    big[s[i]-'a']++;
                }
                i++;
            }
            
            else if(small.size() == k-1 && big.size() == k){
                cnt += big.size() - small.size();
                
                // delete the char from map pointed by left;
                small[s[left]-'a']--;
                if(small[s[left]-'a'] == 0) small.erase(s[left]-'a');
                
                big[s[left]-'a']--;
                if(big[s[left]-'a'] == 0) big.erase(s[left]-'a');
                
                left++;
                
            }
            
        }
        
        return cnt;
        
        
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends