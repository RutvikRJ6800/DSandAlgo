class Solution {
public:
    void fun(string &s,string &temp, vector<string> &res, int idx){
        if(idx==s.size()){
            res.push_back(temp);
            return;
        }

        if((s[idx]>=97 && s[idx]<=122)||(s[idx]>=65 && s[idx]<=90)){
//             keep char
            temp.push_back(s[idx]);
            fun(s,temp,res,idx+1);
            temp.pop_back();
            
            if(s[idx]>=97 && s[idx]<=122){
                temp.push_back(toupper(s[idx]));
                fun(s,temp,res,idx+1);
                temp.pop_back();
            }
            else if(s[idx]>=65 && s[idx]<=90){
                temp.push_back(tolower(s[idx]));
                fun(s,temp,res,idx+1);
                temp.pop_back();
            }
        }
        else{
             temp.push_back(s[idx]);
             fun(s,temp,res,idx+1);
             temp.pop_back();
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        string temp = "";
        fun(s,temp, res, 0);
        return res;
        
    }
};