//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> indegree(V,0); // stores indegree of each vertices.
	    
	    // find indegree of each node on initial configuration
	    for(int i=0; i<V; i++){
	        for(int j=0; j<adj[i].size(); j++){
	            indegree[adj[i][j]]++;
	        }
	    }
	    
	    // kind of multi source bfs algo
	    // at start add node into queue whose indegree is zero.
	    queue<int> qq;
	    for(int i=0; i<V; i++){
	        if(indegree[i] == 0){
	            qq.push(i);
	        }
	    }
	    
	    vector<int> ans;
	    
	    while(!qq.empty()){
	        int node = qq.front();
	        ans.push_back(node);
	        qq.pop();
	        
	        for(auto it: adj[node]){
	            // decrease indegree of adj node's 
	            //and if updated indegree is zero then add it into queue
	            if(--indegree[it] == 0) qq.push(it); 
	        }
	    }
	    
	    return ans;
	    
	    
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends