// https://leetcode.com/problems/lexicographically-smallest-equivalent-string/

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char, char> hm;
        for(char i = 'a'; i<='z'; i++){
            hm[i] = i;
        }

        for(int i=0; i<s1.size(); i++){
            char a = hm[s1[i]];
            char b = hm[s2[i]];

            while(hm[a] != a){
                a = hm[a];
            }
            while(hm[b] != b){
                b = hm[b];
            }

            if(b<a){
                hm[a] = b;
            }
            else if(a < b){
                hm[b] = a;
            }

        }
        string ans = "";

        for(int i=0; i<baseStr.size(); i++){
            char temp = baseStr[i];

            while(hm[temp] != temp){
                temp = hm[temp];
            }

            ans.push_back(temp);
        }

        return ans;
    }
};