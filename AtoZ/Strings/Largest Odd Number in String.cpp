// https://leetcode.com/problems/largest-odd-number-in-string/description/
class Solution {
public:
    string largestOddNumber(string num) {
        
        string ans = "", curr = "";

        for(char c: num){
            curr.push_back(c);

            if((int)(c-'0') % 2 == 1){
                ans = curr;
            }
        }

        return ans;
    }
};