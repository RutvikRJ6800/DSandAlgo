// https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int a[],  int N, int k) 
    { 
        // Complete the function
        int i=0, j=0, n = N, sum = 0, ans = 0;
        while(j<n){
            sum += a[j];
            if(sum < k){
                j++;
            }
            else if(sum >= k){
                
                while(sum > k){
                    sum -= a[i];
                    i++;
                }
    
                if(sum == k){
                    ans = max(ans, j-i+1);
                }
                j++;
            }
        }
        
        return ans;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends