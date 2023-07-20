// https://leetcode.com/problems/string-to-integer-atoi/description/
class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        int sign = 1, i=0, n= s.size(), j=0;
        bool isSigned = true;
        bool canSpace = true;

        while(canSpace || i < n){
            if(s[i] == '-' && isSigned == true){
                sign = -1;
                isSigned = false;
                canSpace = false;
            }
            else if(s[i] == '+' && isSigned == true){
                sign = 1;
                isSigned = false;
                canSpace = false;
            } 
            else if(s[i] >= '0' && s[i] <= '9'){
                isSigned = false;
                canSpace = false;
                ans = ans*10 + (s[i] - '0');
                if(ans>=2147483647){
                    if(sign==1){
                        return INT_MAX;
                    }
                    else if(ans==2147483647){
                        return 2147483647*sign;
                    }
                    else{
                        return INT_MIN;
                    }
                }
                // else if((long long)ans*10 + (long long)(c - '0') > INT_MAX){
                //     ans = (int)(((long long)ans*10 + (long long)(c - '0')) %  INT_MAX);
                // }
                // else{
                //     ans = ans * 10 + (int)(c - '0');
                // }
            }
            else if((s[i] == ' ' && !canSpace) || !isSigned) break;
            else if(s[i] == ' ' && canSpace) {
                j++;
            }
            else return 0;
            i++;
        }

        
        return sign * ans;
    }
};