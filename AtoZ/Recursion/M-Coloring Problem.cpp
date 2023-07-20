// https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool canWeColor(int node, int color, vector<int> &colorMap, vector<vector<int>> &adj){

        for(auto adjNode: adj[node]){
            if(colorMap[adjNode] != -1 && colorMap[adjNode] == color){
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<int>> &adj, int n, int m, vector<int> &colorMap, int node){
        if(node == n){
            // all node get colored
            return true;
        }
        else{
            // color node
            for(int i=0; i<m; i++){
                if(canWeColor(node, i, colorMap, adj)){
                    colorMap[node] = i;
                    
                    if(solve(adj, n, m, colorMap, node+1)) return true;
                    
                    colorMap[node] = -1;
                }
            }
            return false;
        }
        
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<vector<int>> adj;
    
        for(int i=0; i<n; i++){
            vector<int> vec;
            for(int j = 0; j<101; j++){
                if(graph[i][j]){
                    vec.push_back(j);
                }
            }
            adj.push_back(vec);
        }

        vector<int> colorMap(n, -1);
        return solve(adj, n, m, colorMap, 0);
    }
    
    
    /*
    5
1
3
5 1 5 3 4 5
    */
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends