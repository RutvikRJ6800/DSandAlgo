// https://leetcode.com/problems/remove-outermost-parentheses/description/

class Solution {
public:
    void insertCharInStack(stack<char> &st, char c){
        if(c == '('){
            st.push('(');
        }
        else{
            if(st.top() == '('){
                st.pop();
            }
        }
    }
    bool isStackValid(stack<char> &st){
        if(st.empty()) return true;
        else
        return false;
    }
    string removeOuterParentheses(string s) {
        stack<char> st;

        int n = s.size(), i=0;
        string curr = "", ans = "";
        for(char c:s){
            curr.push_back(c);
            insertCharInStack(st, c);

            if(isStackValid(st)){
                // add curr string into ans;
                // cout<<curr<<" # "<<curr.substr(1,curr.size()-1)<<endl;
                ans += curr.substr(1,curr.size()-2);
                curr = "";
            }
        }

        return ans;


    }
};