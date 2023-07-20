// https://leetcode.com/problems/valid-parenthesis-string/description/
class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;
        for(char c: s){
            if(c == '*'){
                low--;
                high++;
            }
            else if(c == '('){
                low++;
                high++;
            }
            else if(c == ')'){
                low--;
                high--;
            }

            if(high < 0) break;
            low = max(low, 0);
        }

        return low == 0;
    }
};