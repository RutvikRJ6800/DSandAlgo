// https://leetcode.com/problems/longest-common-prefix/description/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int n = strs.size(), m = strs[0].size();

        for(int i=0; i<m; ++i){
            
            char c = strs[0][i];
            for(int j = 1; j<n; ++j){

                if(strs[j].size() < (i+1) || strs[j][i] != c){
                    return strs[0].substr(0,i);
                }
            }
        }

        return strs[0];
    }
};