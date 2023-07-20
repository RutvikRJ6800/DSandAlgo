// https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/description/
class Solution {
public:
    int ans = 0;
    void solve(int idx, int req, vector<vector<int>>& requests, vector<int> & indegree, vector<int> &outdegree){
        if(idx == requests.size()){
            bool flag = true;
            for(int i=0; i<indegree.size(); i++){
                if(indegree[i] != outdegree[i]){
                    flag = false;
                }
            }

            if(flag){
                ans = max(ans, req);
            }
        }
        else{
            // take
            indegree[requests[idx][1]]++;
            outdegree[requests[idx][0]]++;
            solve(idx+1, req+1, requests, indegree, outdegree);

            // not take
            indegree[requests[idx][1]]--;
            outdegree[requests[idx][0]]--;
            solve(idx+1, req, requests, indegree, outdegree);
        }
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> indegree(n, 0);
        vector<int> outdegree(n, 0);

        solve(0, 0, requests, indegree, outdegree);

        return ans;

    }
};