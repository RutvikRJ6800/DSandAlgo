// https://leetcode.com/problems/top-k-frequent-elements/description/
typedef pair<int, int> pi;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        // count the freq of all element
        for(int num: nums){
            mp[num]++;
        }

        priority_queue<pi, vector<pi>, greater<pi>> minh;

        // consider top k char with highest freq
        for(auto it: mp){
            minh.push({it.second, it.first});

            if(minh.size()>k){
                minh.pop();
            }
        }

        vector<int> ans;
        while(!minh.empty()){
            ans.push_back(minh.top().second);
            minh.pop();
        }
        return ans;
    }
};