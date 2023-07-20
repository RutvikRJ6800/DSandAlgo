// https://leetcode.com/problems/sort-characters-by-frequency/description/
class Solution {
public:
    static bool cmp(pair<char, int> &a, pair<char, int> &b){
        return a.second > b.second;
    }
    string frequencySort(string s) {
        // map aproscah
        map<char, int> mp;

        for(char c:s){
            mp[c]++;
        }

        string ans = "";

        vector<pair<char, int>> vec;

        for(auto &it: mp){
            vec.push_back(it);
        }

        sort(vec.begin(), vec.end(), cmp);

        for(auto &it: vec){
            while(it.second--){
                ans.push_back(it.first);
            }
        }

        // for(auto [c, i]: mp){
        //     ans.push_back(c);
        // }

        return ans;

        // vector of pair approach
    }
};