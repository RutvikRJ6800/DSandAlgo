#include <bits/stdc++.h>
using namespace std;

bool bfs(int start, vector<int> adj[], vector<bool> &visited){
    visited[start] = 1; // mark start and visited
    queue<pair<int,int>> qq;
    qq.push(make_pair(start, -1));
    
    while(!qq.empty()){
        int node = qq.front().first;
        int parent = qq.front().second;
        qq.pop();
        
        for(auto it: adj[node]){
            if(!visited[it]){
                visited[it] = 1;
                qq.push(make_pair(it, node));
            }
            else if(it != parent){
                return true; // cycle detected here
            }
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
            if(bfs(i, adj, visited)) return "Yes";    
        }
    }
    return "No";
}
