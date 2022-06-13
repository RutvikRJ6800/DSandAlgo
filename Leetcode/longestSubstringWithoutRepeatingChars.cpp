// https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/
// https://www.youtube.com/watch?v=qtVh-XEpsJo&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=26
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0){
            return 0;
        }
        int start=0,end=-1,max=INT_MIN;
        unordered_map<char,int> m;
        
        for(int i=0; i<s.size(); ++i){
        
            if(m.find(s[i])!=m.end()&&m[s[i]]>=start){
                // if char is repeated and exist btw start and end
                start=m[s[i]]+1;
            }        
            m[s[i]]=i; // update index of curr char as i
            end++; // inc end pointer
            if((end-start+1)>max)max=end-start+1; // length of curr substrig = end - start + 1;
        }
        
        return max;
    }
};