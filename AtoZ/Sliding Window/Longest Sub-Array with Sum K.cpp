// https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        unordered_map<int,int> m;
        m[0]=-1;
        int sum=0,ans=0;
        for (int i=0;i<N;i++){
            sum+=A[i];
            int x=sum-K;
            if(m.find(x)!=m.end())  ans=max(ans,i-m[x]);
            if(m.find(sum)==m.end()) m[sum]=i;
        }
        return ans;
    } 
/*
17 15
-13 0 6 15 16 2 15 -12 17 -16 0 -3 19 -3 2 -9 -6
*/
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