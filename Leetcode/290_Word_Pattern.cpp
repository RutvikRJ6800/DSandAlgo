class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int i=0, j=0;
        int n = pattern.size(), m = s.size();
        unordered_map<char, string> hm1;
        unordered_map<string, char> hm2; 

        while(i<n && j<m){
            // get new char and new word
            char c = pattern[i++];

            string currWord = "";
            while(j<m && s[j] != ' '){
                currWord.push_back(s[j++]);
            }
            j++;

            if(hm1.find(c) != hm1.end() && hm1[c] != currWord) return false;
            else if(hm2.find(currWord) != hm2.end() && hm2[currWord] != c) return false;
            else{
                hm1[c] = currWord;
                hm2[currWord] = c;
            }

        }

        if(i<n || j < m) return false;

        return true;
    }
};