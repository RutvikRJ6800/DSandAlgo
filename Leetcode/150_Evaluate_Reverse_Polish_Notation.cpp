// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long int> operand; // stores operand (number in stack)
        int n = tokens.size();
        for(int i=0; i<n; i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){ 
                // operator detected;
                // if curr ele is operator
                // pop top 2 element from the stack and perform operation and store it back in stack
                long long int second = operand.top();
                operand.pop();
                long long int first = operand.top();
                operand.pop();
                long long int res;
                if(tokens[i] == "+"){
                    res = first+second;
                }
                else if(tokens[i] == "-"){
                    res = first-second;
                }
                else if(tokens[i] == "*"){
                    res = first*second;
                }
                else if(tokens[i] == "/"){
                    res = first/second;
                }

                operand.push(res);
            }
            else{
                // operand detected.
                // store it in operand stack
                operand.push(stoi(tokens[i]));
            }
        }

        // if the given expression is valid ezpression then result must be the top element of the stack
        return operand.top();
    }
};