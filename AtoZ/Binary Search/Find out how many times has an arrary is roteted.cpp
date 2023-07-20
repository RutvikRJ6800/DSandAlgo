// https://practice.geeksforgeeks.org/problems/rotation4723/1

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	   // int left = 0, right = n-1, mini = 0;
	    
	    int s=0;
        int e=n-1, mini = INT_MAX, mini_index = -1;

        while(s<=e){
            int mid=s+(e-s)/2;

            // cout<<s<<","<<e<<","<<mid<<endl;
            if(arr[s] <= arr[mid]){
                // left part is sorted
                if(mini > arr[s]){
                    mini = arr[s];
                    mini_index = s;
                }
                s = mid + 1;

            }else{
                // right part is sorted
                if(mini > arr[mid]){
                    mini = arr[mid];
                    mini_index = mid;
                }
                e = mid - 1;
            }
        }

        return mini_index;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends