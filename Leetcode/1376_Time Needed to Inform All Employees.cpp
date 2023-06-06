// https://leetcode.com/problems/time-needed-to-inform-all-employees/description/

class Solution {
public:
    int dfs(int emp, vector<vector<int>> &adj, int n, vector<int>& manager, vector<int>& informTime){

        int currMax = 0;
        for(int i=0; i<adj[emp].size(); ++i){
            int ans = dfs(adj[emp][i], adj, n, manager, informTime);
            currMax = max(currMax, ans);
        }


        if(adj[emp].size() > 0){
            currMax += informTime[emp];
        }

        return currMax;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);

        for(int i=0; i<n; i++){
            if(i==headID) continue;

            adj[manager[i]].push_back(i);
        }

        // queue<int> q;
        // q.push(headID);
        // int time = 0;

        // while(!q.empty()){
        //     int size = q.size();
        //     int currMax = 0;
        //     while(size--){
        //         int emp = q.front();
        //         q.pop();

        //         if(adj[emp].size() > 0){
        //             currMax = max(currMax, informTime[emp]);
        //         }

        //         for(auto it: adj[emp]){
        //             q.push(it);
        //         }

        //     }
        //     cout<<currMax<<" + ";
        //     time += currMax;
        // }

        // return time;


        // using DFS approch
        return dfs(headID, adj, n, manager, informTime);
    }
};