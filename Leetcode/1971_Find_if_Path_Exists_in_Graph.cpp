// https://leetcode.com/problems/find-if-path-exists-in-graph/description/

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);

        // get adjajancy list from edges.
        for(int i=0; i<edges.size(); i++){
            int nodeA = edges[i][0];
            int nodeB = edges[i][1];

            adj[nodeA].push_back(nodeB);
            adj[nodeB].push_back(nodeA);
        }


        // apply bfs with source as starting vertex
        queue<int> q;

        q.push(source);
        vector<bool> visited(n, 0);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            if(node == destination) return true; // if we get destination as visited than return true.(Path exist)

            for(auto it: adj[node]){
                if(!visited[it]){
                    // it node is not visited
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }

        // if we get destination as visited than return false.(Path does not exist)
        return false;
    }
};