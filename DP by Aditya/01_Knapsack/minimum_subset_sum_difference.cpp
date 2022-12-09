#include <bits/stdc++.h>
using namespace std;

/* 
RECURSIVE APPROACH 
int rec(vector<int> &A, int n, int sum, int total){
    if(n==0) return abs(2*sum - total);
    cout<<n<<endl;
    return min(rec(A, n-1, sum+A[n-1], total), rec(A, n-1, sum, total));
}

int solve(vector<int> &A) {
    int n = A.size();
    int total = 0;
    for(int i=0; i<n; i++){
        total += A[i];
    }
    
    return rec(A, n, 0, total);    
} */

/*
// MEMOISATION APPROACH

int rec(vector<int> &A, int n, int sum, int total, vector<vector<int>> &dp){
    if(n==0) return abs(2*sum - total);
    
    if(dp[n][sum] != -1) return dp[n][sum];
    
    dp[n][sum] = min(rec(A, n-1, sum+A[n-1], total, dp), rec(A, n-1, sum, total, dp));
    return dp[n][sum] ;
}

int Solution::solve(vector<int> &A) {
    int n = A.size();
    int total = 0;
    for(int i=0; i<n; i++){
        total += A[i];
    }
    
    vector<vector<int>> dp(n+1, vector<int>(total+1, -1));
    return rec(A, n, 0, total, dp);    
}

*/

// TOP-DOWN APPROACH
int Solution::solve(vector<int> &A) {
    int n = A.size();
    int total = 0;
    for(int i=0; i<n; i++){
        total += A[i];
    }
    
    vector<vector<int>> dp(n+1, vector<int>(total+1, -1));
    
    for(int i=0; i<n+1; i++){
        dp[i][0] = 1;
    }
    
    for(int i=1; i<n+1; i++){
        for(int j=1; j<total+1; j++){
            if(A[i-1]<=j){
                dp[i][j] = (dp[i-1][j-A[i-1]] || dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    vector<int> sum;
    for(int i=0; i<total/2+1; i++){
        if(dp[n][i] == 1) sum.push_back(i);
    }
    
    int minValue = INT_MAX;
    for(int i=0; i<sum.size(); i++){
        int s = sum[i];
        minValue = min(minValue, abs(2*s - total));
    }
    
    return minValue;
}


int main(){

    vector<int> arr = {68, 35, 1, 70, 25, 79, 59, 63, 65, 6, 46, 82, 28, 62, 92, 96, 43, 28, 37, 92, 5, 3, 54, 93, 83, 22, 17, 19, 96, 48, 27, 72, 39, 70, 13, 68, 100, 36, 95, 4, 12, 23, 34, 74, 65, 42, 12, 54, 69, 48, 45};
    cout<<solve(arr);
    return 0;
}