// https://practice.geeksforgeeks.org/problems/1a31d09f7b8e9c0633339df07858deb3a728fe19/1/?page=1&company[]=Microsoft&company[]=Amazon&sortBy=latest#
// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    vector<int> farNumber(int N,vector<int> arr){
        //code here
        
        vector<int> suffix_min(N);
        vector<int> res(N);
        
        suffix_min[N-1]=arr[N-1];
        for(int i=N-2; i>=0; i--){
            
            suffix_min[i]=min(arr[i],suffix_min[i+1]);
            
        }
        
        for(int i=0;i<N;i++){
            
            int small=i+1, large=N-1, ans=-1;
            int mid;
            while(small<=large){
                mid=(small+large)/2;
                if(suffix_min[mid]<arr[i]){
                    ans=mid;
                    small=mid+1;
                }
                else{
                    large=mid-1;
                }
                
            }
            res[i]=ans;
            
        }
        // res[N-1]=-1;
        
        return res;
        
    }
};

// { Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++)
            cin>>Arr[i];
        Solution obj;
        vector<int> answer=obj.farNumber(N,Arr);
        for(auto i:answer)
            cout<<i<<" ";
        cout<<endl;
  }
}  // } Driver Code Ends