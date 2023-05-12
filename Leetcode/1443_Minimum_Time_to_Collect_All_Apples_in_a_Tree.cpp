class Solution {
public:
    int solve(int curr, vector<vector<int>> &adj, vector<bool>& hasApple, vector<int> &visited){
        vector<int> adjList = adj[curr];
        visited[curr] = 1;

        int ans = 0;
        for(int b = 0; b<adjList.size(); b++){
            if(visited[adjList[b]] == 1) continue;
            int temp = solve(adjList[b], adj, hasApple, visited);
            if(temp>0) ans += temp;
        }

        // cout<<curr<<","<<left<<","<<right<<endl;
        if(ans>0){
            return 2 + ans;
        }
        else{
            if(hasApple[curr]) return 2;
            else return -1;
        }
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);

        for(int i=0; i<n-1; i++){
            int a = edges[i][0];
            int b = edges[i][1];

            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> visited(n, 0);
        
        int ans = solve(0, adj, hasApple, visited)-2;
        if(ans<0) return 0;
        else return ans;

    }
};