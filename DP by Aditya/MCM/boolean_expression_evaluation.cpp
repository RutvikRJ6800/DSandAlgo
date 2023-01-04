//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(string e, int i, int j, bool isTrue){
        if(i>j) return 0;
        if(i==j) {
            if(e[i] == 'T') return isTrue;
            else return !isTrue; 
        }

        int ans = 0;
        for(int k=i+1; k<j; k = k+2){
            int ltrue, rtrue, rfalse, lfalse;
            ltrue = solve(e, i, k-1, true);
            lfalse = solve(e, i, k-1, false);
            rtrue = solve(e, k+1, j, true);
            rfalse = solve(e, k+1, j, false);

            if(e[k] == '|'){
                if(isTrue){
                    ans +=  (ltrue * rtrue) + (lfalse * rtrue) + (ltrue * rfalse);
                }
                else{
                    ans += (lfalse * rfalse);
                }
            }
            else if(e[k] == '^'){
                if(isTrue){
                    ans +=  (lfalse * rtrue) + (ltrue * rfalse);
                }
                else{
                    ans += (lfalse * rfalse) + (ltrue * rtrue);
                }
            }
            else if(e[k] == '&'){
                if(isTrue){
                    ans +=   (ltrue * rtrue);
                }
                else{
                    ans += (lfalse * rfalse) +(lfalse * rtrue) + (ltrue * rfalse);
                }
            }
        }

        return ans;
    }
    int countWays(int N, string expression) {
        // int n = expression.size();
        return solve(expression, 0, N-1, true);
    }
    
};
//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
