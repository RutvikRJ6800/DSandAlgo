// https://leetcode.com/problems/daily-temperatures/solutions/1574806/c-easy-standard-sol-intuitive-approach-with-dry-run-stack-appraoch/?orderBy=most_votes
// https://leetcode.com/problems/daily-temperatures/description/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        vector<int> ans(n, 0);

        stack<pair<int, int>> st;

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && st.top().first <= temperatures[i]){
                st.pop();
            }

            if(st.empty()){
                ans[i] = 0;
            }
            else{
                ans[i] = st.top().second - i;
            }
            st.push({temperatures[i], i});
        }

        return ans;
    }
};