// https://leetcode.com/problems/rotate-string/description/
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        string ss = s + s;

        if(ss.find(goal) != string::npos) return true;
        else return false;
    }
};