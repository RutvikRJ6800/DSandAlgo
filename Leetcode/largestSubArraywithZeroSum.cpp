// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        // use hase set- time_O(N) & space_O(N)
        if(n==1){
            if(A[0]==0)return 1;
        }
        unordered_map<int,int> m;
        int maxLength=INT_MIN,sum=0;
        for(int i=0; i<n; i++){
            sum +=A[i];
            if(sum==0){
                if(maxLength<(i+1))maxLength=i+1;
            }
            else if(m.find(sum)!=m.end()){
                if(maxLength<(i-m[sum]))maxLength=i-m[sum];
            }
            else{
                m[sum]=i;
            }
        }
        if(maxLength==INT_MIN){
            return 0;
        }
        return maxLength;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends