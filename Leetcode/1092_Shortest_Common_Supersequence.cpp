// https://leetcode.com/problems/shortest-common-supersequence/description/

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.size();
        int n2 = str2.size();

        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] =  1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        string lcs = "";


        int i = n1, j=n2;

        while(i!=0 && j!=0){
            if(str1[i-1] == str2[j-1]){
                lcs.push_back(str1[i-1]);
                i--;
                j--;
            }
            else if(dp[i-1][j] < dp[i][j-1]){
                j--;
            }
            else{
                i--;
            }
        }

        reverse(lcs.begin(), lcs.end());
        cout<<"lcs: "<<lcs<<endl;

        int k = 0, n3=lcs.size();
        i=0;
        j=0;

        string ans="";
        while(i<n1 && j<n2){
            if( k < n3 && str1[i] == lcs[k] && str2[j] == lcs[k]){
                ans.push_back(lcs[k]);
                i++;
                j++;
                k++;
                continue;
            }

            if(str1[i] != lcs[k]){
                ans.push_back(str1[i]);
                i++;
            }

            if(str2[j] != lcs[k]){
                ans.push_back(str2[j]);
                j++;
            }

        }

        while(i<n1){
            ans.push_back(str1[i]);
            i++;
        }

        while(j<n2){
            ans.push_back(str2[j]);
            j++;
        }

        return ans;
    }
};