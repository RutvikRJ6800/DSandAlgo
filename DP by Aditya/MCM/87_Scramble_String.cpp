// https://leetcode.com/problems/scramble-string/description/
class Solution {
public:
    map<pair<string, string>, bool> hm;
    bool solve(string s1, string s2){
        if(s1.compare(s2) == 0){
            return true;
        }

        if(s1.size()<=1) return false;

        if(hm.find({s1, s2}) != hm.end()) return hm[{s1,s2}];

        int len = s1.size();
        int freq[26] = {0};
        for(int i=0; i<len; i++){
            freq[s1[i] - 'a']++;
            freq[s2[i] - 'a']--;
        }

        for(int i=0; i<26; i++){
            if(freq[i] != 0){
                hm[{s1, s2}] = false;
                return false;
            }
        }

        for(int k=1; k<len; k++){
            // swap
            // if(solve(s1.substr(0,k), s2.substr(len-k,k)) && solve(s1.substr(k,len-k), s2.substr(0,len-k))){ 
            //     hm[{s1,s2}] = true;
            //     return true;}
            bool b1, b2;
            if(hm.find({s1.substr(0,k), s2.substr(len-k, k)}) != hm.end()) b1 = hm[{s1.substr(0,k), s2.substr(len-k, k)}];
            else{
                b1 = solve(s1.substr(0,k), s2.substr(len-k,k));
            }

            if(hm.find({s1.substr(k,len-k), s2.substr(0, len-k)}) != hm.end()) b2 = hm[{s1.substr(k,len-k), s2.substr(0, len-k)}];
            else{
                b2 = solve(s1.substr(k,len-k), s2.substr(0,len-k));
            }

            if(b1 && b2){
                hm[{s1,s2}] = true;
                return true;
            }

            // no swap
            // if(solve(s1.substr(0,k), s2.substr(0,k)) && solve(s1.substr(k,len-k), s2.substr(k,len-k))){
            //     hm[{s1,s2}] = true; 
            //     return true;}
            bool b3, b4;
            if(hm.find({s1.substr(0,k), s2.substr(0, k)}) != hm.end()) b3 = hm[{s1.substr(0,k), s2.substr(0, k)}];
            else{
                b3 = solve(s1.substr(0,k), s2.substr(0,k));
            }

            if(hm.find({s1.substr(k,len-k), s2.substr(k,len-k)}) != hm.end()) b4 = hm[{s1.substr(k,len-k), s2.substr(k,len-k)}];
            else{
                b4 = solve(s1.substr(k,len-k), s2.substr(k,len-k));
            }

            if(b3 && b4){
                hm[{s1,s2}] = true;
                return true;
            }
        }

        hm[{s1, s2}] = false;
        return false;
    }
    bool isScramble(string s1, string s2) {
        int len = s1.size();
        return solve(s1, s2);
    }
};