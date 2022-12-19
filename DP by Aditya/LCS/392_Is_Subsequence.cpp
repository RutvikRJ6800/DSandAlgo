class Solution {
public:
    bool isSubsequence(string s, string t) {
        // BF approach
        int i=0, j=0;
        int n1 = s.size(), n2 = t.size();

        while(i<n1 && j<n2){
            if(s[i] == t[j]){
                // char match
                i++;
                j++;
            }
            else{
                j++;
            }
        }

        if(i==n1) return true;
        else return false;
        
        // also we can solve it using LCS
        // find lcs(s,t) if it is equal to s.size() return true
        // else return false;
    }
};