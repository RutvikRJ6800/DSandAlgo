// https://practice.geeksforgeeks.org/problems/game-of-death-in-a-circle1840/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int solve(int n, int k,  int start, vector<int> &arr){
      if(arr.size() == 1) return arr[0];
      int dead = (start + (k-1)) % arr.size();
      
      arr.erase(arr.begin() + dead);
      
      return solve(n-1, k, dead, arr);
  }
    int safePos(int n, int k) {
        // code here
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            arr[i] = i+1;
        }
        return solve(n, k, 0, arr);
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        
        cin>>n>>k;

        Solution ob;
        cout << ob.safePos(n,k) << endl;
    }
    return 0;
}
// } Driver Code Ends