// https://practice.geeksforgeeks.org/problems/count-squares3649/1#
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int countSquares(int N) {
        // code here
        
        // using for loop
        // int count=0;
        // for(int i=1; i<N; i++){
        //     int sq=i*i;
        //     if(sq<N)count++;
        //     else
        //     break;
        // }
        // return count;
        
        // using mathemetical concept
        float sq=sqrt(N);
        if(floor(sq)!=sq){
            return (int)sq;
        }
        else
        return int(sq)-1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
}  // } Driver Code Ends