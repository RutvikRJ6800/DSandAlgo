//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int check(vector<int> &stalls, int k, int n, int mid){
        int i=1, cnt = 1, curr = stalls[0];
        
        while(i<n){
            curr += mid;
            
            while(i<n && curr>stalls[i]){
                i++;
            }
            
            if(i<n && curr <= stalls[i]){
                cnt++;
                curr = stalls[i];
            }
            i++;
        }
        
        // cout<<cnt<<endl;
        return cnt;
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        
        sort(stalls.begin(), stalls.end());
        
        int left = 0, right = stalls[n-1] - stalls[0], ans = 0;
        
        while(left <= right){
            int mid = left + (right - left)/2;
            
            if(check(stalls, k, n, mid) < k){
                right = mid - 1;
            }
            else{
                left = mid + 1;
                ans = mid;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends