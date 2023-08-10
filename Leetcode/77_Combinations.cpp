// https://leetcode.com/problems/combinations/description/

class Solution {
public:
    void solve(int n, int k, int currEle, vector<int> &curr, vector<vector<int>> &ans){
        if(k==0){
            ans.push_back(curr);
            return;
        }
        if(currEle > n) return;

        int i=currEle;
        while(i<=n){
            // insert this ele
            curr.push_back(i);
            solve(n, k-1, i+1, curr, ans);

            curr.pop_back();
            i++;
        }

        return;
    }
    vector<vector<int>> combine(int n, int k) {
        /*
        RECURSIVE SOLUTION
        vector<int> curr;
        vector<vector<int>> ans;
        solve(n, k, 1, curr, ans);
        return ans;
        */

        // ITERATIVE SOLUTION
        vector<int> curr(k, 0);
        vector<vector<int>> ans;

        for(int start = 0; start <= n-k; start++){
            for(int i = 1; i<=k; i++){
                curr[i-1] = start + i;
            }
            ans.push_back(curr);
        }
        return ans;

    }
};