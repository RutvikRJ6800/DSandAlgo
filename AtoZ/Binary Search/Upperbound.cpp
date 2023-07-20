//  https://practice.geeksforgeeks.org/problems/ceil-the-floor2802/1
//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    
     sort(arr, arr+n);
    pair<int, int>ans;
    int a=-1;
    int b=-1;
    
    int s=0;
    int e=n-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]<=x){
            a=arr[mid];
            s=mid+1;
        }else{
            e=mid-1;
        }
    }
    
    s=0;
    e=n-1;
    
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]>=x){
            b=arr[mid];
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    ans.first=a;
    ans.second=b;
    return ans;
}