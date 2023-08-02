// https://www.codingninjas.com/studio/problems/boolean-evaluation_1214650?leftPanelTab=0
#include <bits/stdc++.h>
long long solve(string &exp, int i, int j, bool needTrue, vector<vector<vector<long long>>> &dp){
    if(i==j){
        if(needTrue) return exp[i] == 'T'?1:0;
        else return exp[i] == 'F'?1:0;
    }
    if(dp[(int)needTrue][i][j] != -1) return dp[(int)needTrue][i][j];

    const unsigned int mod = 1000000007;
    long long ans = 0;
    for(int k=i+1; k<j; k+=2){
        long long leftTrue = solve(exp, i, k-1, 1, dp);
        long long leftFalse = solve(exp, i, k-1, 0, dp);
        long long rightTrue = solve(exp, k+1, j, 1, dp);
        long long rightFalse = solve(exp, k+1, j, 0, dp);
        if(needTrue){
            if(exp[k] == '|'){
            ans += ((leftTrue*rightFalse) % mod + (leftFalse*rightTrue) % mod + (leftTrue*rightTrue) % mod) % mod;
            }
            else if(exp[k] == '&'){
                ans += (leftTrue*rightTrue) % mod;
            }
            else if(exp[k] == '^'){
                ans += ((leftTrue*rightFalse) % mod + (leftFalse*rightTrue) % mod) % mod;
            }
        }
        else{
            if(exp[k] == '|'){
            ans += ((leftFalse*rightFalse) % mod);
            }
            else if(exp[k] == '&'){
                ans += ((leftFalse*rightFalse) % mod + (leftTrue*rightFalse) % mod + (leftFalse*rightTrue) % mod)%mod;
            }
            else if(exp[k] == '^'){
                ans += ((leftTrue*rightTrue) % mod + (leftFalse*rightFalse) % mod)%mod;
            }
        }
        
        // cout<<i<<","<<j<<","<<k<<","<<"isTrue:"<<needTrue<<",ans:"<<ans<<endl;
    }

    dp[(int)needTrue][i][j] = ans%mod;
    return dp[(int)needTrue][i][j];
        
}

int evaluateExp(string & exp) {
    // Write your code here.
    int n=exp.size();
    // vector<vector<vector<int>>> dp(n, vector<vector<int>(n, vector<int>(2, -1)));
    vector<vector<vector<long long>>> dp(2, vector<vector<long long>>(n, vector<long long>(n, -1)));
    return solve(exp, 0, exp.size()-1, 1, dp);
}

/*
F^F^F^F&T|T|F|T|F|F|T|T|T|T&T|T|T&T|F&T|F|T|T|T^T|F^T|T&F^T|F|T|F|T&T|T^F|F^T&T^T&T^T&T^T&F&T^F|F^T|T|F|F^F|F&F|F|T&F&F
*/