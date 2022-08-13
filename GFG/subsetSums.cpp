// https://practice.geeksforgeeks.org/problems/subset-sums2234/1
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void fun(vector<int> &arr,vector<int> &res, int idx, int N, int sum){
        if(idx==N)return res.push_back(sum);
        else{
    
            fun(arr,res ,idx+1,N,sum+arr[idx]);
            
            fun(arr, res, idx+1,N, sum);
        }
        
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> res;
        
        
        
        fun(arr,res,0,N,0);

        
        sort(res.begin(),res.end());
        
        
        return res;
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends