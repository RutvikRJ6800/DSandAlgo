// { Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
// class Solution{
//     public:
//     //Complete this function
//     //Function to check whether there is a subarray present with 0-sum or not.
//     bool subArrayExists(int arr[], int n)
//     {
//         //Your code here
//         set<int> s;
//         int sum=0;
//         for(int i=0; i<n; i++){
//             if(s.find(sum)!=s.end()){
//                 return true;
//             }
//             sum+=arr[i];
//             s.insert(sum);
//         }
//         return false;
//     }
// };

// // { Driver Code Starts.
// // Driver code
int main()
{
	set<int> s;
    int sum=0;
    s.insert(0);
    if(s.find(sum)!=s.end()){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
	return 0;
}  // } Driver Code Ends