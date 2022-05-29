//https://leetcode.com/problems/valid-parentheses/s
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        int size = s.size();
        int i=0;
        
        while(i<size){
            if(s[i]=='{' || s[i]=='[' || s[i]=='('){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    return false;
                }
                char top = st.top();
                if(top == '(' && s[i]==')'){
                    st.pop();
                }
                else if(top == '{' && s[i]=='}'){
                    st.pop();
                }
                else if(top == '[' && s[i]==']'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            i++;
        }
        if(st.empty()){
                return true;
            }
            
                return false;
    }
};