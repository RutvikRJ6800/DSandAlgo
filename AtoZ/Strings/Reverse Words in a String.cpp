// https://leetcode.com/problems/reverse-words-in-a-string/description/
class Solution {
public:
    string reverseWords(string s) {
        
        string curr = "", ans = "";
        for(char c:s){
            if(c==' '){
                if(curr.size() > 0){
                    ans = " " + curr + ans;
                    curr = "";
                } 
            }
            else{
                curr.push_back(c);
            }
        }

        if(curr.size() > 0){
            ans = " "+ curr + ans;
        }

        return ans.substr(1);
    }
};