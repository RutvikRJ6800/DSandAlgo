// { Driver Code Starts
//Initial template for C++
// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1#
// https://www.youtube.com/watch?v=9u2BJfmWNEg&ab_channel=CodeHelp-byBabbar
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> st;
        for(int i=0; i<n; i++){
            st.push(i);
        }
        
        while(st.size()>1){
            int a=st.top();
            st.pop();
            
            int b=st.top();
            st.pop();
            
            // if a knows b that means a cant be celebrity
            if(M[a][b]==1){
                st.push(b);
            }
            // if a dont know b that means b cant be celebrity
            else{
                st.push(a);
            }
        }
        
        
        int candidate = st.top();
        
        // check candidate is really celebrity or not;
        bool rowCheck = true;
        
        for(int i=0; i<n; i++){
            if(M[candidate][i]==1){
                rowCheck = false;
            }
        }
        
        bool colCheck = true;
        
        for(int i=0; i<n; i++){
            if(i==candidate) continue;
            
            if(M[i][candidate]==0){
                colCheck = false;
            }
        }
        
        if(rowCheck && colCheck){
            return candidate;
        }
        else
        return -1;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends