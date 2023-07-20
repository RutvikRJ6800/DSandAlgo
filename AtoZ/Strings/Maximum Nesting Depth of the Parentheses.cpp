// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/
class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int mpd = 0;

        for(char c:s){
            if(c == '('){
                st.push('(');
                mpd = max(mpd, (int)st.size());
            }
            else if(c == ')'){
                if(st.top() == '('){
                    st.pop();
                }
            }
        }

        return mpd;
    }
};