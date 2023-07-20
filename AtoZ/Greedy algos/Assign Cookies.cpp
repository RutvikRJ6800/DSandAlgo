// https://leetcode.com/problems/assign-cookies/description/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n1 = g.size(), n2 = s.size();
        int i=0, j = 0, ans = 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        while(i<n1 && j<n2){
            if(g[i] <= s[j]){
                ans++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};