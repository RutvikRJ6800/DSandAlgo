// https://leetcode.com/problems/string-to-integer-atoi/submissions/
class Solution {
public:
    int myAtoi(string s) {
        size_t size = s.size(), curr=0;
        int sign=1;
        long long res=0;
        // if(size>=1 && s[0]=='-'){
        //     sign=-1;
        //     curr++;
        // }
        bool signB = true;
        bool whiteSpace= true;
        bool leadingZeros=true;
        while(isdigit(s[curr]) || whiteSpace||signB){
            if(s[curr]==' ' && whiteSpace){
                curr++;
            }
            else if((s[curr]=='-' || s[curr]=='+' )&& signB){
                
                if(s[curr]=='-')
                    sign = -1;
                if(s[curr]=='+')
                    sign = 1;
                signB=false;
                whiteSpace=false;
                curr++;
            }
            else if(s[curr]=='0' && leadingZeros){
                curr++;
                whiteSpace = false;
                signB=false;
            }
            
            else if(isdigit(s[curr])){
                leadingZeros=false;
                whiteSpace=false;
                signB=false;
            
                res = res*10 + (s[curr]-'0');
                if(res>=2147483647){
                    if(sign==1){
                        return INT_MAX;
                    }
                    else if(res==2147483647){
                        return 2147483647*sign;
                    }
                    else{
                        return INT_MIN;
                    }
                }
                
                curr++;
            }
            else{
                return 0;
            }
        }
    
        res = res *sign;
        if(res>INT_MAX){
            res=INT_MAX;
        }
        if(res<INT_MIN){
            res=INT_MIN;
        }
        
        
        return res;
    }
};