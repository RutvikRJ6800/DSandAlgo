// https://practice.geeksforgeeks.org/problems/palindrome-string0817/1#
// { Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	
	int isPalindrome(string S)
	{
	    // Your code goes here
	   // O(n) time and O(n) space;
	   
	   // string temp;
	   // for(int i=S.size()-1; i>=0; i--){
	   //     temp.push_back(S[i]);
	   // }
	    
	   // if(S==temp){
	   //     return true;
	   // }
	   // else{
	   //     return false;
	   // }
	   
	   
	   //O(n) time and O(1) space
	   int l,r;
	   l=0;
	   r=S.size()-1;
	   
	   while(l<r){
	       if(S[l]!=S[r]){
	           return 0;
	       }
	       l++;
	       r--;
	   }
	   
	   return 1;
	   
	}

};

// { Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}  // } Driver Code Ends