// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/
// https://www.notion.so/712-Minimum-ASCII-Delete-Sum-for-Two-Strings-9b09f7b5c8a44ae2800884e629970267?pvs=4

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();

        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = (int)s1[i-1] + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }

        int ans=0;
        for(int i=0; i<n1; i++){
            ans += (int)s1[i];
        }
        for(int i=0; i<n2; i++){
            ans += (int)s2[i];
        }

        return ans - 2*dp[n1][n2];
    }
};

/*


Reccurence Relation:
f(i, j){
    //Base case;
    if(i==0){
        return ascii sum of str2[0:j]
    }
    else if(j==0){
        return ascii sum of str1[0:i]
    }

    if(str1[i-1] == str2[j-1]){
        return f(i-1, j-1);
    }
    else{
        // chars of string are not equal
        return min(str1[i-1] + f(i-1, j), str2[j-1] + f(i, j-1));
    }
}

*/