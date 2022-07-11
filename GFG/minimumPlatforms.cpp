// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    
    const static bool cmp(pair<int,int> &p1, pair<int,int> &p2){
        if(p1.first < p2.first){
            return true;
        }
        if(p1.first == p2.first){
            if(p1.second < p2.second){
                return true;
            }
        }
        return false;
    }
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	 sort(arr,arr+n);
        sort(dep,dep+n);
     
        int ans=1;
        int count=1;
        int i=1,j=0;
        while(i<n && j<n)
        {
            if(arr[i]<=dep[j]) //one more platform needed
            {
                count++;
                i++;
            }
            else //one platform can be reduced
            {
                count--;
                j++;
            }
            ans=max(ans,count); //updating the value with the current maximum
        }
        return ans;
        	
    	
    	
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends