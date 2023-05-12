class Solution {
public:
    
    vector<int> solve(int curr, vector<vector<int>> &adj, string &labels, vector<int> &ans, vector<bool> &visited){
        vector<int> alpha(26, 0);
        if(visited[curr]) return alpha;

        vector<int> adjNodes = adj[curr];

        
        visited[curr] = 1;

        for(int i=0; i<adjNodes.size(); i++){
            vector<int> temp = solve(adjNodes[i], adj, labels, ans, visited);
            for(int j=0; j<26; j++){
                alpha[j] += temp[j];
            }
        }
        alpha[labels[curr]-'a']++;
        ans[curr] = alpha[labels[curr]-'a'];

        return alpha;
    }
    
    /*
    unordered_map<char,int> solve(int curr, vector<vector<int>> &adj, string &labels, vector<int> &ans, vector<bool> &visited){
        unordered_map<char,int> alpha;
        if(visited[curr]) return alpha;
    
        vector<int> adjNodes = adj[curr];

        visited[curr] = 1;

        for(int i=0; i<adjNodes.size(); i++){
            unordered_map<char, int> temp = solve(adjNodes[i], adj, labels, ans, visited);
            
            for(auto it: temp){
                alpha[it.first] += it.second;
            }
        }
        alpha[labels[curr]-'a']++;
        ans[curr] = alpha[labels[curr]-'a'];

        return alpha;
    }
    */
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> ans(n,0);
        vector<vector<int>> adj(n);

        for(int i=0; i<n-1; i++){
            int a = edges[i][0];
            int b = edges[i][1];

            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<bool> visited(n,0);
        solve(0, adj, labels, ans, visited);

        return ans;
    }
};