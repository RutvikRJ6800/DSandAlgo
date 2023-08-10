// https://leetcode.com/problems/word-break/description/

class Solution {
public:
    bool isInDict(string &s, int start, int end, vector<string>& wordDict){
        for(int i=0; i<wordDict.size(); i++){
            string word = wordDict[i];
            bool found = true;
            if(word.size() == end-start+1){
                for(int k=0; k<word.size(); k++){
                    if(word[k] != s[start + k]){
                        found = false;
                        break;
                    }
                }
                if(found) return true;
            }            
        }
        return false;
    }
    bool solve(string &s, vector<string>& wordDict, int idx, vector<int> &dp){
        if(idx == s.size()) return true;
        if(dp[idx] != -1) return dp[idx];

        for(int i=idx; i<s.size(); i++){
            if(isInDict(s, idx, i, wordDict)){
                if(solve(s, wordDict, i+1, dp)) return dp[idx] = 1;
            }
        }

        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        return solve(s, wordDict, 0, dp);
    }
};