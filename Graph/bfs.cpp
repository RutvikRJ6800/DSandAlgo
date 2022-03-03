// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        int visited[V];
        for(int j=0;j<V;j++){
            visited[j]=0;
        }
        
        queue<int> q;
        q.push(0);
        visited[0]=1;
        
        
        
        while(q.size()){
            int curr=q.front();
            q.pop();
            ans.push_back(curr);
        //     for(size_t i=0; i<adj[curr].size(); i++){
        //         if(visited[adj[curr][i]]==0){
        //             visited[adj[curr][i]] = 1;
        //             q.push(visited[adj[curr][i]]);
        //         }
        //     }
        // }
        
         for(auto itr : adj[curr]){
          if(visited[itr]== 0){
           q.push(itr);
           visited[itr] = 1;
          }
         }
        
    }
    return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends