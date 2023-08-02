// https://leetcode.com/problems/longest-string-chain/description/

class Solution {
public:
    bool isChain(string prev, string curr){
        int i = prev.size()-1, j = curr.size()-1, diff = 0;
        if(j<=i) return false;
        while(i>=0 && j>=0){
            if(prev[i] == curr[j]){
                i--;
                j--;
            }
            else{
                diff++;
                j--;
            }

            if(diff>1) return false;
        }

        if(i<0 && j>=0){
            diff += (j+1);
        }

        if(diff>1) return false;
        return true;
    }
    static bool cmp(string &a, string& b){
        if(a.size() == b.size()){
            return a<b;
        }
        else
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1);
        sort(words.begin(), words.end(), cmp);

        int longestIncresingChain = 0;
        for(int i=0; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(isChain(words[j], words[i]) && 1 + dp[j] > dp[i]){
                    dp[i] = 1 + dp[j];
                }
            }
            longestIncresingChain = max(longestIncresingChain, dp[i]);
        }

        return longestIncresingChain;
    }
};