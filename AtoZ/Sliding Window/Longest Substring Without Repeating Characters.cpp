// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, n = s.size(), maxi = 1, j =0;

        if(n==0) return 0;
        unordered_map<char, int> mp;

        // for(int j = 0; j<n; j++){
        while(j<n){
            if(mp.find(s[j]) != mp.end() && mp[s[j]] >= i){
                i = mp[s[j]] + 1;
                continue;
            }
            else{
                mp[s[j]] = j;
                j++;
            }

            // if(maxi < j - i){
            //     // cout<<j<<","<<i<<endl;
            //     maxi = j - i;
            // }
            maxi = max(maxi, j-i);

        }
        return maxi;
    }
};