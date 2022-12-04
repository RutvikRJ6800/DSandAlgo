#include <bits/stdc++.h>

bool dfs(int start, int parent, vector<int> adj[], vector<bool> &visited){
    
    for(auto it: adj[start]){
            if(!visited[it]){
                visited[it] = 1;
                if(dfs(it, start, adj, visited)) return true;
            }
            else if(it != parent){
                return true; // cycle detected here
            }
    }
    
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<int> adj[n+1];
    for(size_t i=0; i<edges.size(); i++){
        int a = edges[i][0];
        int b = edges[i][1];
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<bool> visited(n+1,0);
    for(size_t i=1; i<=n; i++){
        // traverse start for all vertices
        if(!visited[i]){
            visited[i] = 1;
            if(dfs(i, -1, adj, visited)) return "Yes";    
        }
    }
    return "No";
}