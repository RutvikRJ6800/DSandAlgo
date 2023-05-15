class Solution {
public:
    int ans = 0;
    int solve(int curr, vector<vector<int>> &adj, string &s){
        vector<int> adjNodes = adj[curr];
        int val1=0, val2= 0;
        for(int i=0; i<adjNodes.size(); i++){
            int temp = solve(adjNodes[i], adj, s);

            if(val1<=temp && s[adjNodes[i]] != s[curr]){
                val2 = val1;
                val1 = temp;
            }
            else if(val2<temp && s[adjNodes[i]] != s[curr]){
                val2 = temp;
            }
        }

        int vPath = (1+val1+val2);
        val1++;
        val2++;
        ans = max({ans, vPath, val1, val2});

        return max(val1, val2);
    }
    int longestPath(vector<int>& parent, string s) {
        int size = parent.size();
        vector<vector<int>> adj(size);
        // vector<> visited(size)
        for(int i=1; i<size; i++){
            adj[parent[i]].push_back(i);
        }

        solve(0, adj, s);
        return ans;
    }
};