// https://leetcode.com/problems/generate-parentheses/description/
class Solution {
public:
    void rec(int openBraces, int closeBraces, vector<string> &ans, string &curr){
        // cout<<openBraces<<", "<<closeBraces<<endl;
        if(openBraces < 0 || closeBraces < 0) return;
        if(openBraces == closeBraces && openBraces == 0){
            ans.push_back(curr);
            return;
        }
        else if(openBraces > closeBraces) return;
        else{
            curr.push_back('(');
            rec(openBraces - 1, closeBraces, ans, curr);
            curr.pop_back();


            curr.push_back(')');
            rec(openBraces, closeBraces - 1, ans, curr);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr = "";

        rec(n, n, ans, curr);

        return ans;
    }
};