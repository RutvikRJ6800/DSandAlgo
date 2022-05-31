// { Driver Code Starts
// https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1#
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        // vector<long long> res(n);
        
        // for(int i=0; i<n; i++){
            
        //     long long greater = -1;
        //     for(int j=i+1; j<n; j++){
        //         if(arr[i]<arr[j]){
        //             greater=arr[j];
        //             break;
        //         }                
        //     }
            
        //     res[i] = greater;
        // }
        // return res;
        
        // if(n<=0){
        //     return res;
        // }
        // stack<long long> st;
        // st.push(0);
        
        // for(int i=1; i<n; ++i){
        //     if(arr[i]>arr[st.top()]){
        //         while(!st.empty() && arr[i]>arr[st.top()]){
        //             res[st.top()]=arr[i];
        //             st.pop();
        //         }
        //         st.push(i);
        //     }
        //     st.push(i);
        // }
        // while(!st.empty()){
        //     res[st.top()]=-1;
        //     st.pop();
        // }
        // return res;
        
       
       
        // aditya varma solution 
        // https://www.youtube.com/watch?v=NXOOYYwpbg4&ab_channel=AdityaVerma
        vector<long long> res;
        stack<long long> s;
        
        for(int i=n-1; i>=0; i--){
            if(s.empty()){
                res.push_back(-1);
            }
            else if(!s.empty() && s.top()>arr[i]){
                res.push_back(s.top());
            }
            else if(!s.empty() && s.top()<=arr[i]){
                while(!s.empty() && s.top()<=arr[i]){
                    s.pop();
                }
                if(s.empty()){
                    res.push_back(-1);
                }
                else{
                    res.push_back(s.top());
                }
            }
            s.push(arr[i]);
        }
        
        reverse(res.begin(),res.end());
        return res;
        
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
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends