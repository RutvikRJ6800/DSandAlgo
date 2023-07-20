// https://leetcode.com/problems/minimum-window-substring/description/

class Solution {
public:

    string minWindow(string s, string t) {
        int n1 = s.size(), n2 = t.size(), i=0, j=0, ansLen = INT_MAX, ansStart=-1, ansEnd = -1;
        if(n1 < n2) return "";

        unordered_map<char, int> freq;
        string ans = "";


        for(int k=0; k<n2; k++){
            freq[t[k]]++;
        }
        
        int cnt = freq.size();

        while(j<n1){
            
            if(freq.find(s[j]) != freq.end()){
                // char present into map
                if(freq[s[j]] == 1){
                    cnt--; // we completed the req for this char
                }
                freq[s[j]]--;
            }

            if(cnt > 0){
                // not all req char present in window so go ahead
                j++;
            }

            if(cnt == 0){
                // can be candidate ans

                while(cnt == 0){
                    if(ansLen > (j-i+1)){
                        ansLen = j - i + 1;
                        ansStart = i;
                        ansEnd = j;
                    }

                    if(freq.find(s[i]) != freq.end()){
                        if(freq[s[i]] == 0){
                            cnt++;
                        }
                        freq[s[i]]++;
                    }
                    i++;
                }

                j++;
            }
        }

        if(ansStart == -1 || ansEnd == -1) return "";
        return s.substr(ansStart, ansEnd - ansStart + 1);
        
    }
};