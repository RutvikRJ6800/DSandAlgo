// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> ans;
        vector<int> indegree(V, 0);
        queue<int> q;
        // vector<vector<int>> adj(numCourses);

        for(int i=0; i<V; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }

        for(int i=0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int course = q.front();
            q.pop();

            ans.push_back(course);
            
            for(auto it: adj[course]){
                indegree[it]--;

                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        if(ans.size() == V) return false;
        else return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends