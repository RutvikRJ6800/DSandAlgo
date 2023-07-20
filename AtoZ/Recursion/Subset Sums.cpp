// https://practice.geeksforgeeks.org/problems/subset-sums2234/1
//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void rec(vector<int>& candidates, int idx, int size, int sum, vector<int> &ans){
        if(idx == size){
           ans.push_back(sum);
           return;
        }
        else{
            // take
            sum += candidates[idx];

            rec(candidates, idx+1, size, sum, ans);

            sum -= candidates[idx];
            
            rec(candidates, idx+1, size, sum, ans);
        }
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        // sort(candidates.begin(), candidates.end());
        rec(arr, 0, N, 0, ans);

        // vector<vector<int>> vecans;
        // for(auto it: ans){
        //     vecans.push_back(it);
        // }

        return ans;
    }
    
};

//{ Driver Code Starts.
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
}
// } Driver Code Ends