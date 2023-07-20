// https://leetcode.com/problems/roman-to-integer/description/
class Solution {
public:
    int romanToInt(string s) {
        int ans = 0, n = s.size(), i=0;

        while(i<n){
            cout<<i<<endl;
            if(i+1 < n && s[i] == 'I'){
                if(s[i+1] == 'V'){
                    ans += 4;
                    i += 2;
                    continue;
                }
                else if(s[i+1] == 'X'){
                    ans += 9;
                    i += 2;
                    continue;
                }
            }
            if(i+1 < n && s[i] == 'X'){
                if(s[i+1] == 'L'){
                    ans += 40;
                    i += 2;
                    continue;
                }
                else if(s[i+1] == 'C'){
                    ans += 90;
                    i += 2;
                    continue;
                }
            }
            if(i+1 < n && s[i] == 'C'){
                if(s[i+1] == 'D'){
                    ans += 400;
                    i += 2;
                    continue;
                }
                else if(s[i+1] == 'M'){
                    ans += 900;
                    i += 2;
                    continue;
                }
            }
            if(s[i] == 'I'){
                ans += 1;
                i++;
            }
            if(s[i] == 'V'){
                ans += 5;
                i++;
            }
            if(s[i] == 'X'){
                ans += 10;
                i++;
            }
            if(s[i] == 'L'){
                ans += 50;
                i++;
            }
            if(s[i] == 'C'){
                ans += 100;
                i++;
            }
            if(s[i] == 'D'){
                ans += 500;
                i++;
            }
            if(s[i] == 'M'){
                ans += 1000;
                i++;
            }
        }

        return ans;
    }
};