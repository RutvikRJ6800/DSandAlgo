// https://leetcode.com/problems/target-sum/description/

class Solution {
public:

    int findTargetSumWays(vector<int>& A, int target) {
        int n = A.size();
        if(n==1){
            if(A[0] == target || A[0] == abs(target)) return 1;
            else return 0;
        }
        int total = 0;
        
        for(int num: A){
            total += num;
        }

        // if((target + total)%2 == 1) return 0;
        if((total+target)%2!=0 || (abs(target)>total) )return 0;
        int s1 = (total + target)/2;

        vector<vector<int>> dp(n+1, vector<int>(s1+1, 0));
    
        
        for(int i=0; i<n+1; i++){
            dp[i][0] = 1;
        }
        
        for(int i=1; i<n+1; i++){
            for(int j=0; j<s1+1; j++){
                if(A[i-1]<=j){
                    dp[i][j] = (dp[i-1][j-A[i-1]] + dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][s1];
    }
};

/*
[1,1,1,1,1]
3
[1]
1
[1]
2
[1000]
-1000
*/