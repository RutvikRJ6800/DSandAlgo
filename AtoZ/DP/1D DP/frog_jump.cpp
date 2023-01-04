//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        int prev2 = 0;
        int prev = abs(height[0]- height[1]);
        
        for(int i = 2; i < n; i++){
            int case1 = prev + abs(height[i-1] - height[i]);
            int case2 = prev2 + abs(height[i-2] - height[i]);
            
            int ans = min(case1, case2);
            
            prev2 = prev;
            prev = ans;
        }
        
        return prev;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends