// https://leetcode.com/problems/combination-sum-iii/description/
class Solution {
public:
    void rec(int k, int n, int sum, vector<int> curr, vector<vector<int>> &ans, int prev){
        if(k==0){
            if(sum == n){
                ans.push_back(curr);
            }
            return;
        }
        else{
            for(int i=prev+1; i<10; ++i){
                if(i>n) break;
                else{
                    curr.push_back(i);
                    rec(k-1, n, sum + i, curr, ans, i);
                    curr.pop_back();
                }
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;

        rec(k, n, 0, curr, ans, 0);

        return ans;
    }
};