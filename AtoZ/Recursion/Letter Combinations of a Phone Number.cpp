// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
class Solution {
public:
    void rec(string digits, int idx, string curr, vector<string> &ans){
        if(idx == digits.size()){
            ans.push_back(curr);
        }
        else{
            if(digits[idx] == '2'){
                for(char c = 'a'; c < 'd'; c++){
                    curr.push_back(c);
                    rec(digits, idx + 1, curr, ans);
                    curr.pop_back();
                }
            }
            else if(digits[idx] == '3'){
                for(char c = 'd'; c < 'g'; c++){
                    curr.push_back(c);
                    rec(digits, idx + 1, curr, ans);
                    curr.pop_back();
                }
            }
            else if(digits[idx] == '4'){
                for(char c = 'g'; c < 'j'; c++){
                    curr.push_back(c);
                    rec(digits, idx + 1, curr, ans);
                    curr.pop_back();
                }
            }
            else if(digits[idx] == '5'){
                for(char c = 'j'; c < 'm'; c++){
                    curr.push_back(c);
                    rec(digits, idx + 1, curr, ans);
                    curr.pop_back();
                }
            }
            else if(digits[idx] == '6'){
                for(char c = 'm'; c < 'p'; c++){
                    curr.push_back(c);
                    rec(digits, idx + 1, curr, ans);
                    curr.pop_back();
                }
            }
            else if(digits[idx] == '7'){
                for(char c = 'p'; c < 't'; c++){
                    curr.push_back(c);
                    rec(digits, idx + 1, curr, ans);
                    curr.pop_back();
                }
            }
            else if(digits[idx] == '8'){
                for(char c = 't'; c < 'w'; c++){
                    curr.push_back(c);
                    rec(digits, idx + 1, curr, ans);
                    curr.pop_back();
                }
            }
            else if(digits[idx] == '9'){
                for(char c = 'w'; c <= 'z'; c++){
                    curr.push_back(c);
                    rec(digits, idx + 1, curr, ans);
                    curr.pop_back();
                }
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string curr = "";
        if(digits.size() == 0){
            return ans;
        }

        rec(digits, 0, curr, ans);

        return ans;
    }
};