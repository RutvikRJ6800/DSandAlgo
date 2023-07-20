// https://leetcode.com/problems/find-eventual-safe-states/description/


class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int> &visited, vector<int> &resp){
        if(visited[node]){
            // already visited by some path
            return false;
        }
        else{
            visited[node] = true;
        }


        for(auto it: graph[node]){
            if(resp[it] == -1){
                resp[it] = dfs(it, graph, visited, resp);
            }
            if(!resp[it]){
                return false;
            }
        }

        visited[node] = false;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int V = graph.size();
        vector<int> resp(V, -1);
        for(int i=0; i<V; i++){
            vector<int> visited(V, 0);
            if(resp[i] == -1){
                resp[i] = dfs(i, graph, visited, resp);
            }

            if(resp[i]){
                ans.push_back(i);
            }
            
        }
        return ans;
    }
};